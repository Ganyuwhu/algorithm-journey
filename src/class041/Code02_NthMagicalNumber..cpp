# include<algorithm>
# include <iostream>
# include<numeric>
using namespace std;

// 一个正整数如果能被 a 或 b 整除，那么它是神奇的。
// 给定三个整数 n , a , b ，返回第 n 个神奇的数字。
// 因为答案可能很大，所以返回答案 对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/nth-magical-number/

// 思路：对于一个正整数 n ，能被 a 整除且小于等于 n 的正整数有 n/a 个，根据容斥原理，能被 a 或 b 整除且小于等于 n 的数一共有
// n / a + n / b - n / lcm(a, b) 个(显然既能被 a 整除又能被 b 整除的充分必要条件是被 lcm(a, b) 整除)。
// 因此可以进行二分搜索查找，初始下界设为1，初始上界设为 n * min(a, b)(这个区间必然存在至少 a 个神奇的数)
// 然后计算[1, mid]上有多少个神奇的数，如果结果小于n，说明答案在后半边，此时令left = mid + 1。
// 如果结果大于等于n，说明答案在左半边，此时令right = mid(不减一是考虑mid就是答案的情形)

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long max = 1e9 + 7;
        long long right = 1LL * n * min(a, b);
        long long left = 1LL;
        long long mid = 1LL;
        while (left < right) {
            mid = left + (right - left) / 2;
            int count = mid / a + mid / b - mid / lcm(a, b);
            if (n > count)
                left = mid + 1;
            else
                right = mid;
        }
        return left % max;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // lcm(a) = a * b / gcd(a, b)
    long lcm(int a, int b) {
        return long(a) * b / gcd(a, b);
    }
};
