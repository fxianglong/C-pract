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

void AdjustDown(HPDataType* a, int n, int root)//���µ���
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;//����

	while (child < n)//ֻҪ���Ӳ���Ҷ�ӽ�㣬�ͼ�������
	{
		if (child + 1 < n && a[child + 1] < a[child])//��֤a[child]��������С�ĺ���
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);//��֤a[parent]���������Ӷ�С

			//���¸���parent��child,�������жϱ�������Ľ��
			parent = child;
			child = 2 * parent + 1;
		}
		else//��ǰ���<��С����
		{
			break;
		}
	}
}

void AdjustUp(HPDataType* a, int n, int child)//���ϵ���
{
	assert(a);
	int parent = (child - 1) / 2;

	while (child > 0)//ֻҪ�����㲻������㣬��һֱ���ϵ���
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			//���±������Ľ��
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)//������(�������ʼ�����飬��������)
{
	assert(hp && a);
	//�Ƚ��������ݿ��������������
	hp->_array = (HPDataType*)malloc(n*sizeof(HPDataType));
	hp->_size = hp->_capacity = n;
	memcpy(hp->_array, a, n*sizeof(HPDataType));

	//����(������С��Ϊ��)
	//�����һ���ڵ�ĸ���㿪ʼ���µ�������ΪҶ�ӽ�㲻�õ����������һ��
	//��Ҷ�ӽ��������һ���ڵ�ĸ���㡣��������->�ϵ�������֤ÿ����㶼��С�ѡ�
	//���µ�����˼���ǣ�����ǰ�ڵ㲻����С�����ʣ�����ǰ���>�������Һ�����С��
	//�Ǹ����ͽ��ý�����Ǹ����ӽ�����Ȼ���жϱ�������Ľ��...ֱ��Ҷ�ӽ��
	int end = hp->_size - 1;//���һ��Ԫ���±�
	for (int i = (end - 1) / 2; i >= 0; i--)
	{
		//���һ���ڵ�ĸ���㿪ʼ������㣬��������µ���
		AdjustDown(hp->_array, hp->_size, i);
	}
}
//ע���������ѵĻ���ֻ��Ҫ�����µ�������AdjustDown()��
//�����޸ļ��ɣ�������ӣ��������С������ӣ����佻��...

void HeapDeStory(Heap* hp)//����
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = hp->_capacity = 0;
}

void HeapPrint(Heap* hp)//��ӡ��
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}


//����һ�����ݺ󣬶ѽṹ���ı�(ԭ���Ǵ�ѣ�ɾ����Ѷ�Ԫ�غ���Ȼ�Ǵ��)
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	//�Ѳ���һ��Ԫ�أ�������ʵ���������β�塣Ҫ�뱣֤�ѽṹ���䣬
	//����Ҫ�Ӹ�Ԫ�ؿ�ʼ���ϵ�����ֱ����������㡣
	//���ϵ�����˼���ǣ�ֻҪ������<���ĸ���㣬�����߽�����
	//Ȼ�����жϽ�����Ľڵ�...
	if (hp->_size == hp->_capacity)//��Ҫ����
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
	//�����Ԫ�����ϵ���(ע�����һ�������������±�)
	AdjustUp(hp->_array, hp->_size, hp->_size - 1);
}
void HeapPop(Heap* hp)//ɾ���Ѷ��󣬶ѽṹ���ı�
{
	assert(hp);
	//���Ѷ�Ԫ�������һ��Ԫ�ؽ�������Ԫ����Ŀ��1(ɾ�����ǶѶ�Ԫ��)
	//Ȼ��ԶѶ���һ�����µ���
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;

	AdjustDown(hp->_array, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)//���ضѶ�Ԫ��
{
	assert(hp);
	return hp->_array[0];
}

int HeapSize(Heap* hp)//���ض���Ԫ�ظ���
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)//�п�(�շ���0)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}

void HeapSort(int* a, int n)//������(����)
{
	assert(a);
	//����������򽨴�ѡ����ô�Ѻ󣬽���βԪ�ؽ���(���Ľ��������)��
	//�ٽ���Ԫ��λ����һ�����µ���...(������Ҫע����ǣ�ÿ������һ��ֵ����
	//�����ʱ����һ�ε����µ������ݳ��ȼ�1�����źõ����ݾͲ��ù���)

	//�����
	int end = n - 1;
	for (int i = (end - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	while (end > 0)//���һ��Ԫ���±겻����һ��Ԫ�أ���һֱ����������...
	{
		Swap(&a[0], &a[end]);//������βԪ��
		AdjustDown(a, end, 0);//��Ԫ�����µ���
		end--;
	}
}

void TopK()
{
	//������N������ѡȡ������ǰK����.
	//ѡȡN������ǰK������һ��С�ѣ�Ȼ����N��ʣ�µ�������Ѷ�Ԫ����ȣ�
	//������ڶѶ�Ԫ�أ��Ƚ��Ѷ�Ԫ��pop��(pop()������Ȼ��֤�ѽṹ)��
	//Ȼ�󽫸�Ԫ�����(push()������Ȼ��֤������)

	const int N = 10000;
	const int K = 100;
	int* a = (int*)malloc(N * sizeof(int));

	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100000;//������Ԫ�س�ʼ��Ϊ0-10��֮������ֵ
	}

	//Ϊ�˺ò��ԣ����Ǹ�10������100000��ֵ
	for (int j = 5; j < 15; j++)
	{
		a[j] = 100000 + j;
	}

	//��ǰK�����ֽ�С��
	Heap h;
	HeapInit(&h, a, K);
	for (int i = K; i < N; ++i)//��ʣ�µ�Ԫ��������Ѷ�Ԫ�رȽϣ�������
	{
		if (a[i] > HeapTop(&h))
		{
			HeapPop(&h);
			HeapPush(&h, a[i]);
		}
	}

	//�����е�K��Ԫ�أ���������ǰK������
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