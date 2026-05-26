# include<iostream>
# include<string>
# include<queue>
using namespace std;

// 二叉树按层序列化和反序列化
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
        queue<TreeNode*> queue_tree;
        queue_tree.push(root);
        serialize_helper(str_tree, queue_tree);
        return str_tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> queue_tree;
        TreeNode* root = deserialize_helper(data);

        return root;
    }

    void serialize_helper(string& str_tree, queue<TreeNode*>& queue_tree) {
        while (queue_tree.size() > 0){
            TreeNode* head = queue_tree.front();
            if (!head) {
                str_tree += "#,";
                queue_tree.pop();
            }
            else {
                str_tree += to_string(head->val);
                str_tree += ',';
                queue_tree.pop();
                queue_tree.push(head->left);
                queue_tree.push(head->right);
            }
        }
    }

    TreeNode* deserialize_helper(string& data) {
        // 1. 装填第一个元素
        TreeNode* root = nullptr;
        queue<TreeNode*> queue_tree;
        int index = 0;
        while (index < data.size()) {
            if (index == 0) {
                while (data[index] != ',') index++;
                string val = data.substr(0, index);
                if (val == "#") {
                    queue_tree.push(root);
                    index++;
                }
                else {
                    root = new TreeNode(stoi(val));
                    queue_tree.push(root);
                    index++;
                }
            }
            else {
                // 2. 读取第一个元素
                TreeNode* head = queue_tree.front();
                if (!head) {
                    queue_tree.pop();
                    continue;
                }

                // 3. 连续读取至多两个data中的字符串
                for (int i = 0; i < 2 && index < data.size(); i++) {
                    int start = index;
                    while (data[index] != ',') index++;
                    string val = data.substr(start, index-start);
                    TreeNode* node = nullptr;

                    if (val == "#") {
                        queue_tree.push(node);
                        index++;
                    }
                    else {
                        node = new TreeNode(stoi(val));
                        queue_tree.push(node);
                        index++;
                    }

                    if (i == 0)
                        head->left = node;
                    else
                        head->right = node;
                }

                queue_tree.pop();
            }
        }
        return root;
    }
};