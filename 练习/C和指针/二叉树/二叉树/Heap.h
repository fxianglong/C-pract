#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<time.h>
#include<memory>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;

void Swap(HPDataType* a, HPDataType* b)
{
	assert(a);
	assert(b);
	HPDataType temp = *a;
	*a = *b;
	*b = temp;
}

void AdjustDown(HPDataType* a, int n, int root)//向下调整
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;//左孩子

	while (child < n)//只要孩子不是叶子结点，就继续调整
	{
		if (child + 1 < n && a[child + 1] < a[child])//保证a[child]里面是最小的孩子
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);//保证a[parent]比两个孩子都小

			//重新更新parent、child,即继续判断被交换后的结点
			parent = child;
			child = 2 * parent + 1;
		}
		else//当前结点<最小孩子
		{
			break;
		}
	}
}

void AdjustUp(HPDataType* a, int n, int child)//向上调整
{
	assert(a);
	int parent = (child - 1) / 2;

	while (child > 0)//只要这个结点不到根结点，就一直向上调整
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			//更新被调整的结点
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)//创建堆(用数组初始化数组，并创建堆)
{
	assert(hp && a);
	//先将数组内容拷贝到堆里的数组
	hp->_array = (HPDataType*)malloc(n*sizeof(HPDataType));
	hp->_size = hp->_capacity = n;
	memcpy(hp->_array, a, n*sizeof(HPDataType));

	//建堆(我们以小堆为例)
	//从最后一个节点的父结点开始向下调整，因为叶子结点不用调整，而最后一个
	//非叶子结点就是最后一个节点的父结点。这样从下->上调整，保证每个结点都是小堆。
	//向下调整的思想是：若当前节点不满足小堆性质，即当前结点>它的左右孩子最小的
	//那个，就将该结点与那个孩子交换，然后判断被交换后的结点...直到叶子结点
	int end = hp->_size - 1;//最后一个元素下标
	for (int i = (end - 1) / 2; i >= 0; i--)
	{
		//最后一个节点的父结点开始到根结点，逐个做向下调整
		AdjustDown(hp->_array, hp->_size, i);
	}
}
//注意如果建大堆的话，只需要将向下调整函数AdjustDown()中
//稍作修改即可，找最大孩子，当父结点小于最大孩子，将其交换...

void HeapDeStory(Heap* hp)//销毁
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = hp->_capacity = 0;
}

void HeapPrint(Heap* hp)//打印堆
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}


//插入一个数据后，堆结构不改变(原来是大堆，删除完堆顶元素后，仍然是大堆)
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	//堆插入一个元素，物理上实际是数组的尾插。要想保证堆结构不变，
	//就需要从该元素开始向上调整，直到它到根结点。
	//向上调整的思想是：只要这个结点<它的父结点，将二者交换，
	//然后再判断交换后的节点...
	if (hp->_size == hp->_capacity)//需要增容
	{
		hp->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
		if (tmp)
		{
			hp->_array = tmp;
		}
		hp->_array[hp->_size] = x;
		hp->_size++;
	}
	//将这个元素向上调整(注意最后一个参数传的是下标)
	AdjustUp(hp->_array, hp->_size, hp->_size - 1);
}
void HeapPop(Heap* hp)//删除堆顶后，堆结构不改变
{
	assert(hp);
	//将堆顶元素与最后一个元素交换，将元素数目减1(删除的是堆顶元素)
	//然后对堆顶做一次向下调整
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;

	AdjustDown(hp->_array, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)//返回堆顶元素
{
	assert(hp);
	return hp->_array[0];
}

int HeapSize(Heap* hp)//返回堆中元素个数
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)//判空(空返回0)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}

void HeapSort(int* a, int n)//堆排序(升序)
{
	assert(a);
	//如果是升序，则建大堆。建好大堆后，将首尾元素交换(最大的交换到最后)，
	//再将首元素位置做一次向下调整...(不过需要注意的是，每将最大的一个值交换
	//到最后时，下一次的向下调整数据长度减1，即排好的数据就不用管了)

	//建大堆
	int end = n - 1;
	for (int i = (end - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	while (end > 0)//最后一个元素下标不到第一个元素，就一直交换，调整...
	{
		Swap(&a[0], &a[end]);//交换首尾元素
		AdjustDown(a, end, 0);//首元素向下调整
		end--;
	}
}

void TopK()
{
	//假设再N个数中选取出最大的前K个数.
	//选取N个数的前K个数建一个小堆，然后用N中剩下的数据与堆顶元素相比，
	//如果大于堆顶元素，先将堆顶元素pop掉(pop()函数仍然保证堆结构)，
	//然后将该元素入堆(push()函数仍然保证堆性质)

	const int N = 10000;
	const int K = 100;
	int* a = (int*)malloc(N * sizeof(int));

	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100000;//将数组元素初始化为0-10万之间的随机值
	}

	//为了好测试，我们赋10个大于100000的值
	for (int j = 5; j < 15; j++)
	{
		a[j] = 100000 + j;
	}

	//用前K个数字建小堆
	Heap h;
	HeapInit(&h, a, K);
	for (int i = K; i < N; ++i)//将剩下的元素依次与堆顶元素比较，大的入堆
	{
		if (a[i] > HeapTop(&h))
		{
			HeapPop(&h);
			HeapPush(&h, a[i]);
		}
	}

	//最后堆中的K个元素，就是最大的前K个数据
	HeapPrint(&h);
}

void Test()
{
	Heap h;
	int a[] = { 2, 7, 8, 0, 0, 7, 5, 3, 7, 9 };
	int sz = sizeof(a) / sizeof(a[0]);
	HeapInit(&h, a, sz);
	HeapPrint(&h);

	//HeapPush(&h, 0);
	//HeapPrint(&h);

	//HeapPop(&h);
	//HeapPrint(&h);
	HeapSort(a, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	TopK();
}