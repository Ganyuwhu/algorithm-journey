# include<iostream>
using namespace std;

// 排序链表
// 要求时间复杂度O(n*logn)，额外空间复杂度O(1)，还要求稳定性
// 数组排序做不到，链表排序可以
// 测试链接 : https://leetcode.cn/problems/sort-list/

// 唯一符合条件的排序方式是归并排序，但是注意只有链表可以满足稳定性要求，如果在数组中则不行

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        head1 = sortList(head1);
        head2 = sortList(head2);

        head = mergeSortList(head1, head2);
        return head;
    }

    // 归并两个有序链表
    ListNode* mergeSortList(ListNode* head1, ListNode* head2) {
        ListNode* newhead = new ListNode(0);
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* p = newhead;

        while (p1 && p2) {
            ListNode* less = p1->val < p2->val ? p1 : p2;
            p1 = p1 == less ? p1->next : p1;
            p2 = p2 == less ? p2->next : p2;
            p->next = less;
            p = p->next;
        }

        p->next = p1 ? p1 : p2;
        return newhead->next;
    }
};
