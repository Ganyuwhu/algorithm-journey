# include<iostream>
# include<vector>
# include<unordered_map>
using namespace std;

// 利用先序与中序遍历序列构造二叉树
// 测试链接 : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        if (preorder.size() * inorder.size() == 0) return root;
        unordered_map<int, int> indexMap;  // 存放inorder中的下标
        // preorder: 根节点 -> 左子树 -> 右子树
        // inorder: 左子树 -> 根节点 -> 右子树
        // 因此，对于每个节点，找到它在inorder中的位置，左侧为其左子树，右侧为其右子树
        // 通过递归的方式构建子树
        int left = 0;
        int right = preorder.size() - 1;
        for (int i = left; i <= right; i++)
            indexMap.insert({inorder[i], i});
        int preIndex = 0;
        root = build(preorder, left, right, preIndex, indexMap);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int l, int r, int& preIndex, unordered_map<int, int>& indexMap) {
        if (l > r) return nullptr;
        int inorderIndex = indexMap[preorder[preIndex]];
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;
        root->left = build(preorder, l, inorderIndex-1, preIndex, indexMap);
        root->right = build(preorder, inorderIndex+1, r, preIndex, indexMap);
        return root;
    }
};