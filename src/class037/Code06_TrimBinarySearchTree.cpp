# include<iostream>
using namespace std;

// 修剪搜索二叉树
// 测试链接 : https://leetcode.cn/problems/trim-a-binary-search-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 核心在于，可以直接修剪掉一整棵子树
        // 对于小于low的最大节点，可以删去该节点并将其左子树一同删去，然后将其右子树变为其父节点的左子树
        // 对于大于high的最小节点，可以删去该节点并将其右子树一同删去，然后将其左子树变为其父节点的右子树
        if (!root) return nullptr;

        // 下面两个if语句是为了找出在区间内的根节点，如果当前根节点值小于low，说明最合适的根节点在其右子树，反之亦然
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
