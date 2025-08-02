// https://leetcode.com/problems/lru-cache/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    pair<int, int> p;
    Node* next;
    Node* prev;
    Node(pair<int, int> p) {
        this -> p = p;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

class LRUCache {
    Node* head;
    Node* tail;
    int capacity;
    int size;
    unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
        head = tail = nullptr;
        this -> capacity = capacity;
        this -> size = 0;
    }
    
    int get(int key) {
        if(!mp.count(key) || mp[key] == nullptr)
            return -1;
        Node* k = mp[key];
        if(k == tail)
            return (k -> p).second;
        if(k -> prev)
            k -> prev -> next = k -> next;
        if(k -> next)
            k -> next -> prev = k -> prev;
        if(k == head)
            head = k -> next;
        tail -> next = k;
        k -> prev = tail;
        tail = k;
        return (k -> p).second;
    }
    
    void put(int key, int value) {
        if(mp[key]) {
            (mp[key] -> p).second = value;
            get(key);
            return;
        }
        if(size == capacity) {
            mp[(head -> p).first] = nullptr;
            Node* oldHead = head;
            head = head -> next;
            if(head)
                head -> prev = nullptr;
            if(!head)
                tail = nullptr;
            delete oldHead;
            size--;
        }
        if(!head) {
            head = new Node(make_pair(key, value));
            mp[key] = head;
            size++;
            tail = head;
            return;
        }
        Node* newNode = new Node(make_pair(key, value));
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
        mp[key] = newNode;
        size++;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
