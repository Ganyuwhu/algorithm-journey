# include<iostream>
using namespace std;

// 普通二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 本题可以分两种情况讨论
        // 1. p和q在不同子树时，根节点为公共祖先；
        // 2. p和q在相同子树时，其中一个为二者的公共祖先；
        // 因此实际上是一个找根节点的问题，注意上面的“子树”为包含二者的最小子树。

        // 空树或p，q有一个为根节点时，说明函数在检索到p或q时直接返回
        if (root == nullptr || p == root || q == root)
            return root;

        // 否则，在左右子树分别寻找
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 这时会出现几种情况
        // 1. left是一个非空值，right是空值，说明右子树不存在p或q，二者都在左子树，那么left就是二者的公共祖先；
        // 2. right是一个非空值，left是空值，上面情况反过来即可；
        // 3. 二者都是非空值，注意在这种情况下，必然是left和right分别为p或q，此时说明二者分别在两个子树内，root为公共祖先；
        // 注意，不存在二者都是空值的情况，因为函数的第一行就保证函数一定会在检索到p或q时返回。

        if (left != nullptr && right != nullptr)
            return root;

        TreeNode* ancestor = left != nullptr ? left : right;
        return ancestor;
    }
};
