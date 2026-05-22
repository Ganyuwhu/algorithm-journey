# include<iostream>
# include <unordered_map>
using namespace std;

class DoubleListNode {
public:
    int key = 0;
    int value = 0;
    DoubleListNode *front = nullptr;
    DoubleListNode *next = nullptr;

    DoubleListNode(int k, int v) {
        key = k;
        value = v;
    }
};

class DoubleList {
public:
    DoubleListNode *head = nullptr;
    DoubleListNode *tail = nullptr;

    void push_back(DoubleListNode *node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            node->front = nullptr;
            node->next = nullptr;
        }
        else {
            tail->next = node;
            node->front = tail;
            node->next = nullptr;
            tail = node;
        }
    }

    void pop_top() {
        if (head == nullptr)
            return;
        else if (head == tail && head != nullptr) {
            DoubleListNode *old_head = head;
            head = nullptr;
            tail = nullptr;
            delete(old_head);
        }
        else {
            DoubleListNode *head_next = head->next;
            head_next->front = nullptr;
            delete(head);
            head = head_next;
        }
    }

    void moveToTail(DoubleListNode *node) {
        if (node == tail)
            return ;
        else if (node == head && node != tail) {
            DoubleListNode *head_next = head->next;
            head_next->front = nullptr;
            tail->next = node;
            node->front = tail;
            node->next = nullptr;

            tail = node;
            head = head_next;
        }
        else {
            DoubleListNode *node_front = node->front;
            DoubleListNode *node_next = node->next;
            node_front->next = node_next;
            node_next->front = node_front;
            tail->next = node;
            node->front = tail;
            node->next = nullptr;

            tail = node;
        }
    }
};

class LRUCache {
public:
    DoubleList myList;
    unordered_map<int, DoubleListNode*> hashMap;
    int size = 0;

    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (hashMap.find(key) == hashMap.end())
            return -1;

        DoubleListNode *node = hashMap[key];
        myList.moveToTail(node);
        return node->value;
    }

    void put(int key, int value) {
        if (hashMap.find(key) == hashMap.end()) {
            DoubleListNode *node = new DoubleListNode(key, value);
            if (hashMap.size() == size) {
                DoubleListNode *old_head = myList.head;

                int old_head_key = old_head->key;
                hashMap.erase(old_head_key);
                myList.pop_top();
            }
            hashMap.insert({key, node});
            myList.push_back(node);
        }
        else {
            DoubleListNode *node = hashMap[key];
            node->value = value;
            myList.moveToTail(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */