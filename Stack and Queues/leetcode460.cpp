// get and put should have O(1) average time complexity
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
        this -> capacity = capacity;
        this -> size = 0;
        this -> minFreq = 0;
    }
    
    int get(int key) {
        if(!keyToValFreq.count(key))
            return -1;
        int value = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;
        freqToKeys[freq + 1].push_back(key);
        keyToValFreq[key].second++;
        freqToKeys[freq].erase(keyToIter[key]);
        if(freqToKeys[freq].empty()) {
            if(freq == minFreq)
                minFreq++;
            freqToKeys.erase(freq);
        }
        keyToIter[key] = --freqToKeys[freq + 1].end();
        return value;
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
            keyToValFreq.erase(k);
            if(freqToKeys[minFreq].empty())
                freqToKeys.erase(minFreq);
            keyToIter.erase(k);
            size--;
        }
        freqToKeys[1].push_back(key);
        keyToValFreq[key] = {value, 1};
        keyToIter[key] = --freqToKeys[1].end();
        minFreq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
