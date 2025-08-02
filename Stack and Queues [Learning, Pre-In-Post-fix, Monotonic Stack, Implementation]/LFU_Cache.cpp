// https://leetcode.com/problems/lfu-cache/
// Hard

// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// It should support the following operations: get and put.
// get(key) - Get the value (will always be non-negative) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item.

// For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

// Follow up:
// Could you do both operations in O(1) time complexity?

#include<bits/stdc++.h>
using namespace std;

class LFUCache {
    int size;
    int minFreq;
    int capacity;
    unordered_map<int, pair<int, int>> keyToValFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;
public:
    LFUCache(int capacity) {
        size = 0;
        minFreq = 0;
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(!keyToValFreq.count(key))
            return -1;
        if(keyToValFreq[key].second == minFreq && freqToKeys[minFreq].size() == 1)
            minFreq++;
        keyToValFreq[key].second++;
        freqToKeys[keyToValFreq[key].second].push_back(key);
        freqToKeys[keyToValFreq[key].second - 1].erase(keyToIter[key]);
        if(!freqToKeys[keyToValFreq[key].second - 1].size())
            freqToKeys.erase(keyToValFreq[key].second - 1);
        keyToIter[key] = --freqToKeys[keyToValFreq[key].second].end();
        return keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        if(keyToValFreq.count(key)) {
            keyToValFreq[key].first = value;
            get(key);
            return;
        }
        if(size == capacity) {
            int k = freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();
            if(!freqToKeys[minFreq].size())
                freqToKeys.erase(minFreq);
            keyToValFreq.erase(k);
            keyToIter.erase(k);
            size--;
        }
        keyToValFreq[key] = {value, 1};
        minFreq = 1;
        size++;
        freqToKeys[1].push_back(key);
        keyToIter[key] = --freqToKeys[1].end();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */