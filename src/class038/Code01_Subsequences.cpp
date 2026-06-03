# include<iostream>
# include<vector>
# include<string>
# include<unordered_set>
using namespace std;

// 字符串的全部子序列
// 子序列本身是可以有重复的，只是这个题目要求去重
// 测试链接 : https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a

class Solution {
public:
    // 1. 使用path来保留路径
    // 2. 使用push_back()来处理添加当前字符的情形，并调用递归；
    // 3. 第2步完毕后，通过pop_back()来处理不添加当前字符的情形，并调用递归
    unordered_set<string> unique_set;
    vector<string> generatePermutation(string s) {
        unique_set = unordered_set<string>();
        string path = "";

        dfs(s, 0, path);

        return vector<string>(unique_set.begin(), unique_set.end());
    }

    void dfs(const string s, int index, string& path) {
        if (index == s.size()) {
            unique_set.insert(path);
            return;
        }

        path.push_back(s[index]);
        dfs(s, index+1, path);

        path.pop_back();
        dfs(s, index+1, path);
    }
};
