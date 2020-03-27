//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
//	vector<int> ans;
//	if (tomatoSlices == 0 || cheeseSlices == 0)
//		return ans;
//	int x = 0, y = 0;
//	for (int i = 0; i<(tomatoSlices / 4); i++)
//	for (int j = 0; j<cheeseSlices; j++){
//		if (4 * i + 2 * j == tomatoSlices&&i + j == cheeseSlices)
//		{
//			x = i; y = j;
//			break;
//		}
//	}
//	if (x != 0 || y != 0){
//		ans.push_back(x);
//		ans.push_back(y);
//	}
//	return ans;
//}
//int main()
//{
//	numOfBurgers(0, 0);
//	return 0;
//}

vector<int> numOfBurgers(int ts, int cs) {
	if (ts - 2 * cs < 0) return{};
	if ((ts - 2 * cs) % 2) return{};
	int x = (ts - 2 * cs) / 2, y = cs - x;
	if (y < 0) return{};
	return{ x, y };
}