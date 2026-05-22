# include<iostream>
# include<unordered_map>
# include<unordered_set>
# include<string>
using namespace std;

class AllOne {
    class DoubleListNode {
    public:
        int count = 0;
        DoubleListNode *prev = nullptr;
        DoubleListNode *next = nullptr;
        unordered_set<string> string_set;

        DoubleListNode() = default;
        DoubleListNode(int c): count(c) {}
    };
    unordered_map<string, DoubleListNode*> keyToNode;
    DoubleListNode *head = nullptr;
    DoubleListNode *tail = nullptr;

    void addNextNode(DoubleListNode* node, int count) {
        DoubleListNode *new_node = new DoubleListNode(count);
        new_node->prev = node;
        new_node->next = node->next;
        node->next = new_node;
        if (new_node->next != nullptr) {
            new_node->next->prev = new_node;
        }
        if (tail == node)
            tail = new_node;
    }

    void removeNode(DoubleListNode* node) {
        DoubleListNode *orev = node->prev;
        DoubleListNode *next = node->next;
        if (node == tail) {
            orev->next = next;
            tail = orev;
        }
        else {
            orev->next = next;
            next->prev = orev;
        }
        delete(node);
    }

public:
    AllOne() {
        head = new DoubleListNode(0);
        tail = head;
    }

    void inc(string key) {
        int count = keyToNode.find(key) == keyToNode.end() ? 0 : keyToNode[key]->count;
        if (count == 0) {
            if (head == tail || head->next->count != 1)
                addNextNode(head, 1);
            head->next->string_set.insert(key);
            keyToNode.insert({key, head->next});
        }
        else {
            DoubleListNode *save = keyToNode[key];
            save->string_set.erase(key);
            if (save == tail || save->next->count != count + 1)
                addNextNode(save, count+1);
            save->next->string_set.insert(key);
            keyToNode[key] = save->next;
            if (save->string_set.size() == 0)
                removeNode(save);
        }
    }

    void dec(string key) {
        DoubleListNode *save = keyToNode[key];
        int count = save->count;
        save->string_set.erase(key);

        if (count == 1) {
            if (save->string_set.size() == 0)
                removeNode(save);
            keyToNode.erase(key);
        }
        else {
            if (save->prev->count != count - 1)
                addNextNode(save->prev, count - 1);
            save->prev->string_set.insert(key);
            keyToNode[key] = save->prev;
            if (save->string_set.size() == 0)
                removeNode(save);
        }
    }

    string getMaxKey() {
        if (tail != head) {
            auto it = tail->string_set.begin();
            return *it;
        }
        else
            return "";
    }

    string getMinKey() {
        if (tail != head) {
            auto it = head->next->string_set.begin();
            return *it;
        }
        else
            return "";
    }
};