# include<iostream>
using namespace std;

// 复制带随机指针的链表
// 测试链接 : https://leetcode.cn/problems/copy-list-with-random-pointer/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        // 1. 第一次遍历, 在每个原节点后添加一个影子节点, 影子节点的random为原节点的random
        Node* p = head;
        while (p) {
            Node* shadow = new Node(p->val);
            shadow->next = p->next;
            shadow->random = p->random;
            p->next = shadow;
            p = shadow->next;
        }

        // 2. 修改影子节点的random, 将其改为原random的next
        p = head;
        while (p) {
            Node* shadow = p->next;
            shadow->random = shadow->random == nullptr ? nullptr : shadow->random->next;
            p = shadow->next;
        }

        // 3. 将影子节点从原链表中分离
        p = head;
        Node* newhead = new Node(p->val);
        Node* np = newhead;
        while(p) {
            Node* shadow = p->next;
            p->next = shadow->next;
            np->next = shadow;
            p = p->next;
            np = np->next;
        }

        return newhead->next;
    }
};
