# include<iostream>
# include<vector>
using namespace std;

// 汉诺塔问题，这里使用LeetCode上的面试题086
// 测试链接：https://leetcode.cn/problems/hanota-lcci/

// 汉诺塔问题解法
// 假设三根柱子分别为from to 和 help，最初有n个圆盘在from上
// 递归的思想是，先将from最上面的n-1个圆盘移到help上，然后将最底下的圆盘移到to上，再将help上的所有圆盘移到to上
// 由此可知n阶汉诺塔问题T(n) = 2*T(n-1) + 1 = 2^n - 1

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        hanoi(n, A, C, B);
    }

    void hanoi(int i, vector<int>& from, vector<int>& to, vector<int>& help) {
        if (i == 0) return;
        else {
            hanoi(i-1, from, help, to);
            int top = from.back();
            from.pop_back();
            to.push_back(top);
            hanoi(i-1, help, to, from);
        }
    }
};
