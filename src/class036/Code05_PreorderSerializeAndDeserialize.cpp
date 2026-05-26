# include<iostream>
# include<string>
using namespace std;

// 二叉树的先序序列化和反序列化
// 测试链接 : https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str_tree;
        serialize_helper(root, str_tree);
        return str_tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        TreeNode *root = deserialize_helper(data, index);
        return root;
    }

private:
    void serialize_helper(TreeNode* root, string &str) {
        if (!root) {
            str += "#,";
        }
        else {
            str += to_string(root->val) + ',';
            serialize_helper(root->left, str);
            serialize_helper(root->right, str);
        }
    }

    TreeNode* deserialize_helper(const string& data, int& index) {
        if (data[index] == '#') {
            index += 2;
            return nullptr;
        }
        else {
            int start = index;
            while (data[index] != ',')
                index++;
            string val = data.substr(start, index - start);
            TreeNode* node = new TreeNode(stoi(val));
            index++; // 跳过','
            node->left = deserialize_helper(data, index);
            node->right = deserialize_helper(data, index);
            return node;
        }
    }
};
