# include <iostream>
using namespace std;

// 返回两个无环链表相交的第一个节点
// 测试链接 : https://leetcode.cn/problems/intersection-of-two-linked-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB) {
            if (pA != nullptr)
                pA = pA -> next;
            else
                pA = headB;

            if (pB != nullptr)
                pB = pB -> next;
            else
                pB = headA;
        }
        return pA;
    }
};
