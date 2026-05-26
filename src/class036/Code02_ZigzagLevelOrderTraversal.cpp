# include <iostream>
# include<vector>
# include<deque>
# include<algorithm>
using namespace std;

// 二叉树的锯齿形层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. 比较笨的解法，用deque
class Solution1 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<deque<int>> help;
        vector<vector<int>> ans;
        zigOrder(root, 0, help);

        for (auto dq: help)
            ans.push_back(vector<int>(dq.begin(), dq.end()));

        return ans;
    }

    void zigOrder(TreeNode *root, int depth, vector<deque<int>> &help) {
        if (!root) return;

        if (depth == help.size()) help.push_back({});

        if (depth % 2 == 0) help[depth].push_back(root->val);
        else help[depth].push_front(root->val);

        if (root->left) zigOrder(root->left, depth+1, help);
        if (root->right) zigOrder(root->right, depth+1, help);
    }
};


// 2. 仅用vector：反转奇数层(但是有人说用reverse方法面试不给分，慎用)
class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);

        // 反转奇数层
        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;


    void dfs(TreeNode* root, int depth, vector<vector<int>>& result) {
        if (!root) return;

        if (depth == result.size()) {
            result.push_back({});
        }

        result[depth].push_back(root->val);
        dfs(root->left, depth + 1, result);
        dfs(root->right, depth + 1, result);
    }
};
