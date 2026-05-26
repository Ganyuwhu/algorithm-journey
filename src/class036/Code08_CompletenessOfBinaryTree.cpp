# include<iostream>
# include<queue>
using namespace std;

// 验证完全二叉树
// 测试链接 : https://leetcode.cn/problems/check-completeness-of-a-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        // 本质为层序遍历时，不允许在读取到nullptr时后面仍然出现有效节点
        queue<TreeNode*> nodes;
        if (!root) return true;

        nodes.push(root);
        bool existNULL = false;
        while(nodes.size() > 0) {
            TreeNode* head = nodes.front();
            if (!head) {
                existNULL = true;
                nodes.pop();
            }
            else {
                if (existNULL)
                    return false;
                nodes.push(head->left);
                nodes.push(head->right);
                nodes.pop();
            }
        }
        return true;
    }
};
