# include<iostream>
# include<vector>
using namespace std;

// 二叉树的最大特殊宽度
// 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<unsigned long long>> code_number;
    int widthOfBinaryTree(TreeNode* root) {
        pre(root, 0, 0, code_number);
        int max = 0;
        for (auto level: code_number) {
            int width = level.back() - level.front() + 1;
            if (width > max) max = width;
        }
        return max;
    }

    void pre(TreeNode *root, unsigned long long code, int depth, vector<vector<unsigned long long>> &tree) {
        if (!root) return;

        if (depth == tree.size()) tree.push_back({});

        tree[depth].push_back(code);
        if (root->left) pre(root->left, 2 * code + 1, depth + 1, tree);
        if (root->right) pre(root->right, 2 * code + 2, depth + 1, tree);
    }
};
