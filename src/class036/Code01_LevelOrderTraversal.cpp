# include<iostream>
# include<vector>
using namespace std;

// 二叉树的层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-level-order-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tree;
        pre(root, 0, tree);
        return tree;
    }

    // 注意这里ans的内层vector其实只在意左右顺序，因此中序遍历和后序遍历实际上都可以做到
    void pre(TreeNode* root, int depth, vector<vector<int>> &ans) {
        if (!root) return;

        if (depth == ans.size()) ans.push_back({});

        ans[depth].push_back(root->val);
        if (root->left) pre(root->left, depth+1, ans);
        if (root->right) pre(root->right, depth+1, ans);
    }
};
