//#include<iostream>
//#include<vector>
//using namespace std;
//void max_heapify(vector<int>& arr, int start, int end)
//{
//	//�������ڵ�ָ����ӽڵ�ָ��
//	int dad = start;
//	int son = dad * 2 + 1;
//	while (son <= end)  //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
//	{
//		if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
//			son++;
//		if (arr[dad] > arr[son]) //������ڵ����ӽڵ���������ϣ�ֱ����������
//			return;
//		else  //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
//		{
//			swap(arr[dad], arr[son]);
//			dad = son;
//			son = dad * 2 + 1;
//		}
//	}
//}
//
//void heap_sort(vector<int> &arr, int len)
//{
//	//��ʼ����i������һ�����ڵ㿪ʼ����
//	for (int i = len / 2 - 1; i >= 0; i--)
//		max_heapify(arr, i, len - 1);
//	//�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
//	for (int i = len - 1; i > 0; i--)
//	{
//		swap(arr[0], arr[i]);
//		max_heapify(arr, 0, i - 1);
//	}
//}
//
//int main()
//{
//	vector<int> res;
//	int tmp = 0;
//	cout << "������Ҫ��������ֲ��������ַ���Ϊ��β" << endl;
//	while (cin >> tmp)
//	{
//		res.push_back(tmp);
//	}
//	heap_sort(res, res.size());
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << endl;
//	system("pause");
//	return 0;
//}