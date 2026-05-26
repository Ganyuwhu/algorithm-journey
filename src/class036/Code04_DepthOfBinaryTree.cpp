# include<iostream>
using namespace std;


// 求二叉树的最大、最小深度
// 测试链接: https://leetcode.cn/problems/maximum-depth-of-binary-tree/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left_depth = maxDepth(root->left) + 1;
        int right_depth = maxDepth(root->right) + 1;
        int maxDepth = left_depth > right_depth ? left_depth : right_depth;
        return maxDepth;
    }
};

// 测试链接: https://leetcode.cn/problems/minimum-depth-of-binary-tree/
class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;

        // 如果只有一个子树，那么将另一边设置成节点数最大值
        int left_depth = 1e5 + 1;
        int right_depth = 1e5 + 1;

        if (root->left) left_depth = minDepth(root->left);
        if (root->right) right_depth = minDepth(root->right);

        int minDepth = left_depth < right_depth ? left_depth : right_depth;

        return minDepth + 1;
    }
};
