//
// Created by neha2 on 02-06-2022.
//

#include "LRU.h"
#include<bits/stdc++.h>

using namespace std;

class LRUCache {
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> store;
    list<int> q;
public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        store.reserve(capacity);
    }

    void putAtFrontQueue(list<int>::iterator it) {
        q.splice(q.begin(), q, it); //crux of O(1)
    }

    int get(int key) {
        if (store.find(key) != store.end()) {
            putAtFrontQueue(store[key].second);
            return store[key].first;
        }
        return -1;
    }

    int evictKey(int key) {
        int eKey = q.back();
        q.pop_back();
        return eKey;
    }

    bool isStoreEmpty() {
        if (store.size() < capacity)
            return true;
        return false;
    }

    void put(int key, int value) {
        if (store.find(key) != store.end()) {
            pair<int, list<int>::iterator> oldpair = store[key];
            putAtFrontQueue(oldpair.second);
            store[key].first = value;

        } else if (isStoreEmpty()) {
            q.push_front(key);
            store[key] = make_pair(value, q.begin());
        } else {
            int eKey = evictKey(key);
            auto old=store[eKey];
            store.erase(eKey);
            q.push_front(key);
            store[key] = make_pair(value, q.begin());
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache *obj = new LRUCache(2);
    cout << obj->get(1) << endl;
    obj->put(1, 10);
    obj->put(2, 10);
    obj->put(3, 10);
    cout << obj->get(2) << endl;
    cout << obj->get(1) << endl;
}