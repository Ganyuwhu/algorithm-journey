# include <iostream>

// 求完全二叉树的节点个数
// 测试链接 : https://leetcode.cn/problems/count-complete-tree-nodes/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. 递归方法，但是没有用到完全二叉树的条件，是个二叉树都能这么做
// 因此本题实际上考察的是完全二叉树的性质
class Solution1 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// 2. 非递归方法
// 必须考虑完全二叉树的性质，由于完全二叉树从左到右排列，因此可以统计root的左右子树的高度l_height和r_height，方法为一路访问左孩子。
// 如果l_height > r_height，说明右子树必定为满二叉树，然后令root = root->left，继续如此统计；
// 如果l_height = r_height，说明左子树必定为满二叉树，此时令root = root->right，继续如此统计；
// 满二叉树节点数计算公式：2^height - 1;
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int l_height = get_height(root->left);
        int r_height = get_height(root->right);
        int l_nodes = 0;
        int r_nodes = 0;
        if (l_height > r_height) {
            l_nodes = countNodes(root->left);
            r_nodes = (1 << r_height) - 1;
        }
        else {
            l_nodes = (1 << l_height) - 1;
            r_nodes = countNodes(root->right);
        }
        return 1 + l_nodes + r_nodes;
    }

    int get_height(TreeNode* root) {
        if (!root) return 0;
        int i = 0;
        while (root) {
            root = root->left;
            i++;
        }
        return i;
    }
};
