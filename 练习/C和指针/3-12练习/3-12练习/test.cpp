//#include <iostream>
//#include <iomanip>
//#include<cstring>
//using namespace std;
//int has[25][25];//有无蘑菇
//double dp[25][25];//能够到达每个格子的概率
//
//int main(){
//	int n, m, k;
//	while (cin >> n >> m >> k){
//		int i, j;
//		memset(has, 0, sizeof(has));
//		memset(dp, 0, sizeof(dp));
//		int x, y;
//		for (i = 0; i < k; ++i){
//			cin >> x >> y;
//			has[x][y] = 1;
//		}
//		for (i = 1; i <= n; ++i){
//			for (j = 1; j <= m; ++j){
//				if (i == 1 && j == 1) { dp[1][1] = 1; continue; }
//				if (has[i][j]) { dp[i][j] = 0; continue; }
//				if (i == n && j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; continue; }
//				if (i == n) { dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1]; continue; }
//				if (j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5; continue; }
//				if (i == 1) { dp[i][j] = dp[i][j - 1] * 0.5; continue; }
//				if (j == 1) { dp[i][j] = dp[i - 1][j] * 0.5; continue; }
//				dp[i][j] = dp[i][j - 1] * 0.5 + dp[i - 1][j] * 0.5;
//			}
//		}
//		cout << fixed << setprecision(2) << dp[n][m] << endl;
//	}
//	return 0;
//}



//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#define N 1001
//using namespace std;
//int m, n;
//char ch;
//int maps[N][N];
//int vis[N][N];
//int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//int cnt;
//void dfs(int x, int y)
//{
//	for (int i = 0; i<4; i++)
//	{
//		int nx = x + dir[i][0];
//		int ny = y + dir[i][1];
//		if (nx >= 1 && ny >= 1 && nx <= n&&ny <= m&&vis[nx][ny] == 0 && maps[nx][ny] == 1)
//		{
//			vis[nx][ny] = 1;
//			cnt++;
//			dfs(nx, ny);
//		}
//	}
//}
//int main()
//{
//	while (scanf("%d%d", &m, &n) != EOF&&m&&n)
//	{
//		int x, y;
//		cnt = 1;
//		memset(vis, 0, sizeof(vis));
//		memset(maps, 0, sizeof(maps));
//
//		for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//		{
//			cin >> ch;
//			if (ch == '@')
//			{
//				x = i;
//				y = j;
//				maps[i][j] = 1;
//			}
//			if (ch == '.')
//				maps[i][j] = 1;
//			if (ch == '#')
//				maps[i][j] = 0;
//		}
//		vis[x][y] = 1;
//		dfs(x, y);
//		cout << cnt << endl;
//	}
//	return 0;
//}



//#include <iostream>
//#include <vector>
//using namespace std;
//int blackCount = 0;
//void searchMap(vector<vector<char>>&map, int posX, int posY, int w, int h, int &blackCount)
//{
//	if (posX<0 || posY<0 || posX >= h || posY >= w || map[posX][posY] == '#')
//		return;
//	blackCount++;
//
//	map[posX][posY] = '#';
//
//	searchMap(map, posX, posY - 1, w, h, blackCount);
//
//	searchMap(map, posX, posY + 1, w, h, blackCount);
//
//	searchMap(map, posX - 1, posY, w, h, blackCount);
//
//	searchMap(map, posX + 1, posY, w, h, blackCount);
//
//}
//int main()
//{
//	while (1) {
//		int w, h;
//		cin >> w >> h;
//		if (w == 0 && h == 0)
//			return 0;
//		vector<vector<char>> vc(22, vector<char>(22));
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				char inC;
//				cin >> inC;
//				vc[i][j] = inC;
//			}
//		}
//
//
//		int x = 0, y = 0;
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				if (vc[i][j] == '@')
//				{
//					x = i;
//					y = j;
//					break;
//				}
//			}
//		}
//
//		searchMap(vc, x, y, w, h, blackCount);
//
//		cout << blackCount << endl;
//		vc.clear();
//		blackCount = 0;
//	}
//}


#include<iostream>
#include<Windows.h>
using namespace std;
DWORD WINAPI Fun1Proc(LPVOID lpParameter);//thread data
DWORD WINAPI Fun2Proc(LPVOID lpParameter);//thread data

int index = 0;
int tickets = 10;
HANDLE hMutex;
int main()
{
	HANDLE hThread1;
	HANDLE hThread2;
	//创建线程

	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	//创建互斥对象
	hMutex = CreateMutex(NULL, TRUE,"tickets");
	if (hMutex)
	{
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			cout << "only one instance can run!" << endl;
			return 0;
		}
	}
	WaitForSingleObject(hMutex, INFINITE);
	ReleaseMutex(hMutex);
	ReleaseMutex(hMutex);

	Sleep(4000);
	return 0;
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter)//thread data
{
	while (1){
		ReleaseMutex(hMutex);
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0){
			Sleep(1);
			cout << "thread1sell tickets:" << tickets-- << endl;
		}
		else
		{
			break;
		}
		ReleaseMutex(hMutex);
	}
	return 0;
}
DWORD WINAPI Fun2Proc(LPVOID lpParameter)//thread data
{
	while (1){
		ReleaseMutex(hMutex);
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0){
			Sleep(1);
			cout << "thread1sel2 tickets:" << tickets-- << endl;
		}
		else
		{
			break;
		}
		ReleaseMutex(hMutex);
	}
	return 0;
}









