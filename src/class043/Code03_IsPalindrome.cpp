# include<iostream>
using namespace std;

// 超级回文数中的一个小函数，本身也是一道题 : 判断一个数字是不是回文数
// 测试链接 : https://leetcode.cn/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int head = 1;
        int back = 1;
        while (x / head / 10 > 0)
            head *= 10;

        while (head > back) {
            if ((x / head) % 10 != (x / back) % 10) return false;
            head /= 10;
            back *= 10;
        }
        return true;
    }
};
