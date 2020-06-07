#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<unordered_map>


class Solution {
public:
	//判断两个单词能否互相转换
	bool check_transform(string &word1, string &word2){

		int difference = 0;
		for (int i = 0; i < word1.length() && difference < 2; i++){

			if (word1[i] != word2[i])
				difference++;
		}

		return difference == 1;
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

		unordered_map<string, int> wordId;  //word->ID的映射
		vector<string> idWord;  //ID->word的映射
		vector<vector<int>> edges;  //构造图

		int id = 0;
		for (int i = 0; i < wordList.size(); i++){

			if (!wordId.count(wordList[i])){

				wordId[wordList[i]] = id++;
				idWord.push_back(wordList[i]);
			}
		}

		if (!wordId.count(endWord))
			return{};  //不存在结束单词，返回空

		if (!wordId.count(beginWord)){

			wordId[beginWord] = id++;   //加入起始单词
			idWord.push_back(beginWord);
		}


		//构造图
		edges.resize(id);
		for (int i = 0; i < idWord.size(); i++){

			for (int j = i + 1; j < idWord.size(); j++){

				if (check_transform(idWord[i], idWord[j])){

					edges[i].push_back(j);
					edges[j].push_back(i);  //构造两条有向边
				}
			}
		}

		int endWord_id = wordId[endWord];
		vector<vector<string>> res;
		queue<vector<int>> q;
		q.push(vector<int>{wordId[beginWord]}); //起始单词作为一个路径入队

		//cost[id]：从起始单词出发，转换到id所代表的单词所需的次数(代价)
		vector<int> cost(id, INT_MAX);
		cost[wordId[beginWord]] = 0;

		while (!q.empty()){

			vector<int> now_path = q.front();
			q.pop();

			int last_word_id = now_path.back();

			//当前路径最后一个为结束单词时
			if (last_word_id == endWord_id){

				vector<string> temp;
				for (int i = 0; i < now_path.size(); i++){

					temp.push_back(idWord[now_path[i]]);
				}
				res.push_back(temp);
			}
			else{

				for (int i = 0; i < edges[last_word_id].size(); i++){

					//路径最后一个单词的连接单词
					int next = edges[last_word_id][i];
					if (cost[last_word_id] + 1 <= cost[next]){

						cost[next] = cost[last_word_id] + 1; //更新转换次数 

						vector<int> temp(now_path.begin(), now_path.end());
						temp.push_back(next);
						q.push(temp);
					}
				}
			}

		}

		return res;
	}
};