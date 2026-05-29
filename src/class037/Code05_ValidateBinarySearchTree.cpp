# include<iostream>
using namespace std;

// 验证搜索二叉树
// 测试链接 : https://leetcode.cn/problems/validate-binary-search-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    long long int prev = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        // 需要满足的条件是左子树 < 根节点 < 右子树
        // 因此可以使用中序遍历，二叉搜索树的中序遍历一定是一个升序序列，用一个全局变量prev维护上一个子树的根节点，当root->val < prev时，说明不是二叉搜索树
        if (!root) return true;
        if (!isValidBST(root->left))
            return false;

        if (root->val <= prev)
            return false;

        prev = root->val;

        return isValidBST(root->right);
    }
};
