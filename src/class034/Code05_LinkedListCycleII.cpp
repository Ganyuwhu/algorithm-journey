# include<iostream>
using namespace std;

// 返回链表的第一个入环节点
// 测试链接 : https://leetcode.cn/problems/linked-list-cycle-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        // 1. 使用快慢指针, 若两个指针相遇, 说明有环
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }

        if (!fast->next || !fast->next->next)
            return nullptr;

        // 2. 将快指针放回head, 让快慢指针每次都只走一步, 下次相遇的节点就是初始入环节点
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
