# include<iostream>
using namespace std;

// 判断链表是否是回文结构
// 测试链接 : https://leetcode.cn/problems/palindrome-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return false;
        // 1. 使用快慢指针找终点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 2. 若fast->next == nullptr说明是奇数链表否则为偶数链表
        ListNode* l1 = slow;
        ListNode* l2 = slow;
        if (fast->next)
            l2 = slow->next;

        // 3. 反转l2及其后面的节点, 反转后p1为后半链表的新表头
        ListNode* p1 = l2;
        ListNode* p2 = l2->next;
        while (p2) {
            if (p1 == l2) {
                l1->next = nullptr;
                l2->next = nullptr;
            }
            ListNode* p = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p;
        }

        // 4. 判断
        bool result = true;
        ListNode* np = p1;
        p2 = head;
        while (p1 && p2) {
            if (p1->val != p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 5. 还原链表
        p1 = np;
        p2 = p1->next;
        while (p2) {
            if (p1 == np)
                p1->next = nullptr;
            ListNode* p = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p;
        }
        if (l1 != l2) l1->next = l2;

        return result;
    }
};
