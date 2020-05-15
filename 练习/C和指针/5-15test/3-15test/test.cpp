#include<iostream>
#include<random>
using namespace std;
#include<queue>
#include<functional>

//int main()
//{
//	priority_queue<int, vector<int>, greater<int> > myQueue;   //����һ���յ����ȶ���,�����ȶ�����һ��С����
//	uniform_int_distribution<unsigned> u(0, 100);    //������0��100֮�����ɾ��ȷֲ��������
//	default_random_engine e;     //����һ�����������
//	int value;
//	for (int i = 0; i<10; i++)
//	{
//		value = u(e);
//		cout << value << " ";
//		myQueue.push(value);    //�����ɵ���������뵽������
//	}
//	cout << endl;
//	while (!myQueue.empty())    //��ѭ�����ᰴ������������ȶ����е�Ԫ��
//	{
//		cout << myQueue.top() << " ";    //�����������С��Ԫ��
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
//	friend bool operator<(const node &n1, const node &n2)    //����<����������ڴ󶥶�
//	{
//		return n1.m_x<n2.m_x;
//	}
//	friend bool operator>(const node &n1, const node &n2)    //����>�����������С����
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
//	int T;//���ʴ���
//	long long n, m, black, white, a, b, c, d, e;
//	scanf("%d", &T);//�������ʴ���
//	while (T--)
//	{
//		scanf("%lld%lld", &n, &m);//�������̴�С
//		black = n*m / 2;//��ɫ��������Ϊ�ܷ�������һ�룬����ܷ�����Ϊż�����ڰ׷�������һ�������Ϊ���������ط���Ȱ�ɫ��һ��
//		white = n*m - black;//��ɫ��������
//		for (int i = 0; i <= 3; i++)
//			scanf("%lld%lld", &x[i], &y[i]);
//		if ((x[0] + y[0]) & 1)//Ϳ���������ڰ׷���������
//			d = ((x[1] - x[0] + 1)*(y[1] - y[0] + 1)+1) / 2;//����Ϊ������˵�����Ϊ��ɫ
//		else
//		{
//			d = ((x[1] - x[0] + 1)*(y[1] - y[0] + 1)) / 2;//���Ϊż����˵�����Ϊ��ɫ
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
void ins(int pos, int x){//��posλ�ú�߼�һ����X
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