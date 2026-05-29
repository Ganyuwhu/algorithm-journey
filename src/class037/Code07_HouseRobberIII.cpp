# include<iostream>
# include<vector>
using namespace  std;

// 二叉树打家劫舍问题
// 测试链接 : https://leetcode.cn/problems/house-robber-iii/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode*> vec;
    int rob(TreeNode* root) {
        // 对于每个节点而言，有如下三种情况:
        // 1. 偷当前节点，它的子节点必定不能被偷；
        // 2. 不偷当前节点，偷它的子节点；
        // 3. 不偷当前节点，也不偷它的子节点。
        // 对于两种不偷的情形，考虑它们的较大值。
        vector<int> robValue = dfs(root);
        return max(robValue[0], robValue[1]);
    }

    // 返回包含两个int的vector，第一个表示偷当前节点获得的值，第二个表示不偷当前节点，是否偷下一个节点的最大值
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        int robCurrent = root->val + left[1] + right[1];
        int notrobCurrent = max(left[0], left[1]) + max(right[0], right[1]);

        return {robCurrent, notrobCurrent};
    }
};
