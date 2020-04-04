/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the
following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise
return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its
capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;

template<typename KeyType, typename ValueType>
struct CacheNode {
	KeyType key;
	ValueType value;
};

template<typename KeyType, typename ValueType>
class LRUCache {
public:
	typedef CacheNode<KeyType, ValueType> NodeType;
	typedef typename std::list<NodeType>::iterator IterType; //这里一定要加typename!!!

	IterType NotFound() {
		return list_.end();
	}

	LRUCache(size_t capacity) :
		capacity_(capacity), size_(0) {
	}

	void Insert(const KeyType &key, const ValueType&value) {
		auto pos = mp_.find(key);
		if (pos != mp_.end()) { //原来有移到头部
			list_.splice(list_.begin(), list_, mp_[key]);
			mp_[key] = list_.begin();
			return;
		}
		//原来没有
		if (size_ == capacity_) { //容量满
			mp_.erase(list_.back().key);
			list_.pop_back();
			--size_;
		}
		list_.push_front(NodeType{ key,value });
		mp_.insert({ key,list_.begin() });
		++size_;
	}

	IterType get(const KeyType&key) {
		auto it = mp_.find(key);
		if (it != mp_.end()) {
			//置为最近使用
			list_.splice(list_.begin(), list_, mp_[key]);
			mp_.insert({ key,list_.begin() });
			return mp_[key];

			/*NodeType node = *(it->second);
			list_.erase(it->second);
			return list_.insert(list_.begin(), node);*/ //报错，不知道为什么
		}
		return NotFound();
	}


private:
	size_t capacity_;
	size_t size_;
	std::list<NodeType> list_;
	std::unordered_map<KeyType, IterType> mp_; 
	//std::unordered_map<KeyType, decltype(list_.begin())> mp_; //简单一点直接这样
};


int main() {
	LRUCache<int, std::string> cache(3);
	cache.Insert(1, "1");
	cache.Insert(2, "2");
	cache.Insert(3, "3");
	assert((*cache.get(3)).value == "3");
	assert((*cache.get(2)).value == "2");
	assert((*cache.get(1)).value == "1");

	cache.Insert(4, "4");
	assert((cache.get(3)) == cache.NotFound());
	assert((*cache.get(1)).value == "1");
	assert((*cache.get(2)).value == "2");
	assert((*cache.get(4)).value == "4");


	return 0;
}