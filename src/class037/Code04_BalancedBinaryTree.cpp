# include<iostream>
using namespace std;

// 验证平衡二叉树
// 测试链接 : https://leetcode.cn/problems/balanced-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool balance = true;
    bool isBalanced(TreeNode* root) {
        balance = true;
        height(root);
        return balance;
    }

    int height(TreeNode* root) {
        // 这一行使得只要存在一个节点使得balance=false，后续所有的height都会直接跳出不再对balance做任何操作
        if (!root || !balance) return 0;

        int l_height = height(root->left);
        int r_height = height(root->right);
        if (abs(l_height - r_height) > 1) {
            balance = false;
        return max(l_height, r_height) + 1;
        }
    }
};
