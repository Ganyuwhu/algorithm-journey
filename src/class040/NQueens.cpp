# include<iostream>
using namespace std;

// N皇后问题
// 测试链接 : https://leetcode.cn/problems/n-queens-ii/

// 1. 数组解法，递归
class Solution1 {
public:
    int totalNQueens(int n) {
        int* array = new int[n];
        int ans = find(0, array, n);
        return ans;
    }

    int check(int* array, int i, int j) {
        for (int k = 0; k < i; k++) {
            if (j == array[k] || abs(i - k) == abs(j - array[k]))
                return 0;
        }
        return 1;
    }

    int find(int i, int* array, int n) {
        if (i == n) return 1;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (check(array, i, j)) {
                array[i] = j;
                ans += find(i+1, array, n);
            }
        }
        return ans;
    }
};

// 2. 位运算解法
class Solution2 {
public:
    int totalNQueens(int n) {
        int result = find(n, 0, 0, 0);
        return result;
    }

    int find(int n, int col, int left, int right) {
        // col: 已被占领的列
        // left: 左对角线被占领的列
        // right: 右对角线被占领的列
        if (col == (1 << n) - 1)  // 如果最后n位都为1
            return 1;

        int count = 0;
        int avail = ((1 << n) - 1) & ~(col | left | right);
        while (avail) {
            int p = avail & (-avail);  // 取出最低位的1
            avail -= p;  // 消去最低位的1
            count += find(n, col | p, (left | p) << 1, (right | p) >> 1);
        }
        return count;
    }
};
