# include<iostream>
using namespace std;

// 每k个节点一组翻转链表
// 测试链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 几个要注意的点
// 1. 上一组的表尾需要链接到下一组的表头，但是如果是按原表顺序反转，下一组的表头会变，所以可以记录一下上一组的表尾，在下一组翻转后将其接到上一组的表尾后面
// 2. 不足k个节点的组不用翻转

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        if (k == 1) return head;
        ListNode* start = head;
        ListNode* end = nullptr;
        ListNode* newhead = nullptr;
        ListNode* formerend = nullptr;
        ListNode* nexthead = nullptr;
        while (true) {
            end = findKGroup(start, k);
            if (!end) break;
            if (start == head) newhead = end;
            ListNode* p1 = start;
            ListNode* p2 = p1->next;
            while (p1 != end) {
                if (p1 == start) {
                    p1->next = end->next;
                    nexthead = end->next;
                }
                ListNode* p = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p;
            }
            if (formerend) formerend->next = end;
            formerend = start;
            start = nexthead;
        }
        return newhead;
    }

    static ListNode* findKGroup(ListNode* head, int k) {
        ListNode* end = head;
        int i = 1;
        while (end && i < k) {
            end = end->next;
            i++;
        }
        return end;
    }
};
