# include<iostream>
# include<vector>
using namespace std;

// 收集累加和等于aim的所有路径
// 测试链接 : https://leetcode.cn/problems/path-sum-ii/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> pathCache;
    vector<vector<int>> path;
    int target = 0;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // 1. 使用一个vector<vector<int>> path来存放路径，其中每个元素包含一条累加和为targetSum的完整路径；
        // 2. 使用一个累加函数f(TreeNode* node, int sum, vector<int> vec)来获取节点以及当前路径的累加和
        // 3. 在访问完左右子树或者自身为叶子节点时，将自身从pathCache中弹出
        target = targetSum;
        pathCache = vector<int>();
        path = vector<vector<int>>();

        if (root) expandPath(root, 0);
        return path;
    }

    void expandPath(TreeNode* node, int sum) {
        sum += node->val;
        pathCache.push_back(node->val);
        if (!node->left && !node->right) {
            if (sum == target)
                path.push_back(vector<int>(pathCache));
        }
        else {
            if (node->left)
                expandPath(node->left, sum);
            if (node->right)
                expandPath(node->right, sum);
        }
        pathCache.pop_back();
    }
};
