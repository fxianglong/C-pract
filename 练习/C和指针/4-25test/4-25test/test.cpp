#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
	LRUCache(int capacity) : _cap(capacity) {}

	// O(1)
	// hash ���ң�����ҵ��ˣ��Ͱ� list �еĽڵ�������Ƶ�ͷ��
	int get(int key) {
		auto it = _m.find(key);
		if (it == _m.end()) return -1;
		int val = it->second->second;
		_list.erase(it->second);
		_list.push_front(make_pair(key, val));
		_m[key] = _list.begin();
		return it->second->second;
	}

	// O(1)
	// �Ȳ��Ҿ� key �Ƿ���ڣ�������ڣ����ڵ��ƶ����ײ���
	// ��������ڣ������½ڵ㡣
	// ����������ޣ�ɾ������Ľڵ㡣
	void put(int key, int value) {
		auto it = _m.find(key);
		if (it != _m.end()) {
			_list.erase(it->second);
		}

		_list.push_front(make_pair(key, value));
		_m[key] = _list.begin();

		if (_list.size() > _cap) {
			int key = _list.back().first;
			_m.erase(key);
			_list.pop_back();
		}
	}
private:
	unordered_map<int, list<pair<int, int>>::iterator> _m;
	// �½ڵ��շ��ʵĽڵ�����ͷ����Ϊ��ͷָ�����ͨ�� begin �ܷ���Ļ�ȡ����
	list<pair<int, int>> _list;
	int _cap;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/