#include<iostream>
#include<random>
using namespace std;
#include<queue>
#include<functional>

//int main()
//{
//	priority_queue<int, vector<int>, greater<int> > myQueue;   //构造一个空的优先队列,此优先队列是一个小顶堆
//	uniform_int_distribution<unsigned> u(0, 100);    //用于在0到100之间生成均匀分布的随机数
//	default_random_engine e;     //定义一个随机数引擎
//	int value;
//	for (int i = 0; i<10; i++)
//	{
//		value = u(e);
//		cout << value << " ";
//		myQueue.push(value);    //将生成的随机数放入到队列中
//	}
//	cout << endl;
//	while (!myQueue.empty())    //此循环将会按照升序输出优先队列中的元素
//	{
//		cout << myQueue.top() << " ";    //输出队列中最小的元素
//		myQueue.pop();
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<random>
//using namespace std;
//#include<queue>
//
//class node
//{
//public:
//	node(int x = 0, int y = 0) :m_x(x), m_y(y){}
//	friend bool operator<(const node &n1, const node &n2)    //重载<运算符是用于大顶堆
//	{
//		return n1.m_x<n2.m_x;
//	}
//	friend bool operator>(const node &n1, const node &n2)    //重载>运算符是用于小顶堆
//	{
//		return n1.m_x>n2.m_x;
//	}
//	friend ostream &operator<<(ostream &out, const node &n)
//	{
//		cout << "(" << n.m_x << "," << n.m_y << ")";
//		return out;
//	}
//private:
//	int m_x, m_y;
//};
//int main()
//{
//	priority_queue<node, vector<node>, greater<node> > myQueue;
//	uniform_int_distribution<unsigned> u(0, 100);
//	default_random_engine e;
//	int value1, value2;
//	for (int i = 0; i<10; i++)
//	{
//		value1 = u(e);
//		value2 = u(e);
//		cout << "(" << value1 << "," << value2 << ")";
//		myQueue.push(node(value1, value2));
//	}
//	cout << endl;
//	while (!myQueue.empty())
//	{
//		cout << myQueue.top() << " ";
//		myQueue.pop();
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//using namespace std;
//long long x[8], y[8];
//int main()
//{
//	int T;//提问次数
//	long long n, m, black, white, a, b, c, d, e;
//	scanf("%d", &T);//输入提问次数
//	while (T--)
//	{
//		scanf("%lld%lld", &n, &m);//输入棋盘大小
//		black = n*m / 2;//黑色方块数量为总方块数的一半，如果总方块数为偶数，黑白方块数量一样，如果为奇数，黑素方块比白色少一块
//		white = n*m - black;//白色方块数量
//		for (int i = 0; i <= 3; i++)
//			scanf("%lld%lld", &x[i], &y[i]);
//		if ((x[0] + y[0]) & 1)//涂白起点决定黑白方块数量差
//			d = ((x[1] - x[0] + 1)*(y[1] - y[0] + 1)+1) / 2;//起点和为奇数，说明起点为黑色
//		else
//		{
//			d = ((x[1] - x[0] + 1)*(y[1] - y[0] + 1)) / 2;//起点为偶数，说明起点为白色
//		}
//		white += d;
//		black -= d;
//		if ((x[2] + y[2]) & 1)
//			d = (x[3] - x[2] + 1)*(y[3] - y[2] + 1) / 2;
//		else
//		{
//			d = ((x[3] - x[2] + 1)*(y[3] - y[2] + 1)+1) / 2;
//		}
//		white -= d;
//		black += d;
//		a = max(x[0], x[2]);
//		b = max(y[0], y[2]);
//		c = min(x[1], x[3]);
//		d = min(y[1], y[3]);
//		if (c < a || d < b)e = 0ll;
//		else
//		{
//			if ((a + b) & 1)
//				e = ((c - a + 1)*(d - b + 1) + 1) / 2;
//			else
//			{
//				e = (c - a + 1)*(d - b + 1) / 2;
//			}
//		}
//		white -= e;
//		black += e;
//		printf("%lld	%lld\n", white, black);
//	}
//	system("pause");
//	return 0;
//}


#include<iostream>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9;

struct P
{
	int value;
	int pos;
};
P a[N];
int cmp(P x, P y)
{
	return x.value < y.value;
}
int b[N], b2[N], cnt, head, tail, ans1[N], ans2[N];
struct node
{
	int value;
	int next, pre;
}e[N];

void init(){
	cnt = 2;
	head = 1, tail = 2;
	e[head].next = tail;
	e[head].pre = head;
}
void ins(int pos, int x){//在pos位置后边加一个数X
	e[++cnt].value = x;
	e[cnt].next = e[pos].next;
	e[cnt].pre = pos;
	e[e[pos].next].pre = cnt;
	e[pos].next = cnt;
}

void del(int pos){
	e[e[pos].next].pre = e[pos].pre;
	e[e[pos].pre].next = e[pos].next;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].value);
		a[i].pos = i;
	}
	sort(a + 1, a + 1 + n,cmp);
	init();
	for (int i = 1; i <= n; i++)
	{
		ins(e[tail].pre, a[i].value);
		b[a[i].pos] = cnt;
		b2[cnt] = a[i].pos;
	}
	for (int i = n; i >= 2; --i)
	{
		ans1[i] = inf;
		if (e[b[i]].next != tail){
			ans1[i] = min(ans1[i], abs(e[b[i]].value - e[e[b[i]].next].value));
			ans2[i] = b2[e[b[i]].next];
		}
		if (e[b[i]].pre != head){
			if (ans1[i] >= abs(e[b[i]].value - e[e[b[i]].pre].value)){
				ans1[i] = abs(e[b[i]].value - e[e[b[i]].pre].value);
				ans2[i] = b2[e[b[i]].pre];
			}
		}
		del(b[i]);
	}
	for (int i = 2; i <= n; i++)printf("%d %d\n", ans1[i], ans2[i]);
	system("pause");
	return 0;
}