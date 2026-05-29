# include<iostream>
# include<algorithm>
using namespace std;

// 搜索二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        while (root->val < min(p->val, q->val) || root->val > max(p->val, q->val))
            root = root->val < min(p->val, q->val) ? root->right : root->left;
        return root;
    }
};
