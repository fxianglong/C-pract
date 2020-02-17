//#include<iostream>
//#include<ctime>
//#include<cstring>
//#include<cstdlib>
//using namespace std;
///**将a开头的长为length的数组和b开头长为right的数组合并n为数组长度，用于最后一组*/
//void Merge(int* data, int a, int b, int length, int n){
//	int right;
//	if (b + length - 1 >= n - 1) right = n - b;
//	else right = length;
//	int* temp = new int[length + right];
//	int i = 0, j = 0;
//	while (i <= length - 1 && j <= right - 1){
//		if (data[a + i] <= data[b + j]){
//			temp[i + j] = data[a + i]; i++;
//		}
//		else{
//			temp[i + j] = data[b + j];
//			j++;
//		}
//	}
//	if (j == right){//a中还有元素，且全都比b中的大,a[i]还未使用
//		memcpy(temp + i + j, data + a + i, (length - i) * sizeof(int));
//	}
//	else if (i == length){
//		memcpy(temp + i + j, data + b + j, (right - j)*sizeof(int));
//	}
//	memcpy(data + a, temp, (right + length) * sizeof(int));
//	delete[] temp;
//}
//void MergeSort(int* data, int n){
//	int step = 1;
//	while (step < n){
//		for (int i = 0; i <= n - step - 1; i += 2 * step)
//			Merge(data, i, i + step, step, n);
//		//将i和i+step这两个有序序列进行合并
//		//序列长度为step
//		//当i以后的长度小于或者等于step时，退出
//		step *= 2;//在按某一步长归并序列之后，步长加倍
//	}
//}
//int main(){
//	int n;
//	cin >> n;
//	int* data = new int[n];
//	if (!data) exit(1);
//	int k = n;
//	while (k--){
//		cin >> data[n - k - 1];
//	}
//	clock_t s = clock();
//	MergeSort(data, n);
//	clock_t e = clock();
//	k = n;
//	while (k--){
//		cout << data[n - k - 1] << ' ';
//	}
//	cout << endl;
//	cout << "the algorithm used" << e - s << "miliseconds." << endl;
//	delete data;
//	system("pause");
//	return 0;
//}