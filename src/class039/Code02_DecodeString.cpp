# include<iostream>
# include<string>
using namespace std;

// 含有嵌套的字符串解码
// 测试链接 : https://leetcode.cn/problems/decode-string/

// 1. 使用全局变量pos维护当前访问的位置
// 2. 遇到连续数字时，通过cur * 10 + s[pos] - '0'来计算重复次数
// 3. 遇到左括号时，pos++，并调用递归函数
// 4. 遇到右括号时，pos++并返回当前函数的结果
// 5. 其余情况，正常将其添加到ans中

class Solution {
public:
    int pos = 0;
    string decodeString(string s) {
        pos = 0;
        string ans = decodeSubstring(s, pos);
        return ans;
    }

    string decodeSubstring(string s, int& pos) {
        string ans;
        int cur = 0;
        cout << s[pos];
        while(pos < s.size()) {
            if (s[pos] >= '0' && s[pos] <= '9') {
                cur = cur * 10 + s[pos] - '0';
                pos++;
            }
            else if (s[pos] == '[') {
                pos++;
                string subString = decodeSubstring(s, pos);
                while (cur--) ans += subString;
                cur = 0;
            }
            else if (s[pos] == ']') {
                pos++;
                return ans;
            }
            else
                ans += s[pos++];
        }
        return ans;
    }
};
