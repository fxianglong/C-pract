//#include <unistd.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <pthread.h>
//void *rout(void *arg) {
//	int i;
//	for (;;) {
//		printf("I'am thread 1\n");
//		sleep(1);
//	}
//}
//
//int main(void)
//{
//	pthread_t tid;
//	int ret;
//	if ((ret = pthread_create(&tid, NULL, rout, NULL)) != 0) {
//		fprintf(stderr, "pthread_create : %s\n", strerror(ret));
//		exit(EXIT_FAILURE);
//	}
//
//	int i;
//	for (;;) {
//		printf("I'am main thread\n");
//		sleep(1);
//	}
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <pthread.h>
//
//void *thread1(void *arg)
//{
//	printf("thread 1 returning ... \n");
//	int *p = (int*)malloc(sizeof(int));
//	*p = 1;
//	return (void*)p;
//}
//void *thread2(void *arg)
//{
//	printf("thread 2 exiting ...\n");
//	int *p = (int*)malloc(sizeof(int));
//	*p = 2;
//	pthread_exit((void*)p);
//}
//
//void *thread3(void *arg)
//{
//	while (1){  
//		printf("thread 3 is running ...\n");
//		sleep(1);
//	}
//	return NULL;
//}
//
//int main(void)
//{
//	pthread_t tid;
//	void *ret;
// 
//	pthread_create(&tid, NULL, thread1, NULL);
//	pthread_join(tid, &ret);
//	printf("thread return, thread id %X, return code:%d\n", tid, *(int*)ret);
//	free(ret);
// 
//	pthread_create(&tid, NULL, thread2, NULL);
//	pthread_join(tid, &ret);
//	printf("thread return, thread id %X, return code:%d\n", tid, *(int*)ret);
//	free(ret);
// 
//	pthread_create(&tid, NULL, thread3, NULL);
//	sleep(3);
//	pthread_cancel(tid);
//	pthread_join(tid, &ret);
//	if (ret == PTHREAD_CANCELED)
//		printf("thread return, thread id %X, return code:PTHREAD_CANCELED\n", tid);
//	else
//		printf("thread return, thread id %X, return code:NULL\n", tid);
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <pthread.h>
//
//void *thread_run(void * arg)
//{
//	pthread_detach(pthread_self());
//	printf("%s\n", (char*)arg);
//	return NULL;
//}
//
//int main(void)
//{
//	pthread_t tid;
//	if (pthread_create(&tid, NULL, thread_run, "thread1 run...") != 0) {
//		printf("create thread error\n");
//		return 1;
//	}
//
//	int ret = 0;
//	sleep(1);
//
//	if (pthread_join(tid, NULL) == 0) {
//		printf("pthread wait success\n");
//		ret = 0;
//	}
//	else {
//		printf("pthread wait failed\n");
//		ret = 1;
//	}
//	return ret;
//}


//class Solution {
//public:
//	vector<vector<string>> groupAnagrams(vector<string>& strs) {
//		vector<vector<string>> ans;
//		map<string, int> mmap;
//		for (int i = 0; i<strs.size(); i++)
//		{
//			string s = strs[i];
//			sort(s.begin(), s.end());
//			auto it = mmap.find(s);
//			if (it == mmap.end())
//			{
//				ans.push_back(vector<string>{strs[i]});
//				mmap[s] = ans.size() - 1;
//			}
//			else{
//				auto index = it->second;
//				ans[index].push_back(strs[i]);
//			}
//		}
//		return ans;
//	}
//};

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int strToInt(string str) {
	int Flag = 1; int l = 0; long sum = 0;
	while (str[l] == ' ' || str[l] == '+')l++;
	if (str[l] == '-'){ Flag = -1; l++; }
	while (l<str.size())
	{
		if (str[l] >= '0'&&str[l] <= '9')
		{
			sum = sum * 10 + (str[l] - '0');
			if (Flag == 1 && sum*Flag>INT_MAX)    return INT_MAX;
			if (Flag == -1 && sum*Flag<INT_MIN)    return INT_MIN;
		}
		else{
			break;
		}
		l++;
	}
	return sum*Flag;
}
int main()
{
	string ans = { "+-2" };
	strToInt(ans);
	return 0;
}