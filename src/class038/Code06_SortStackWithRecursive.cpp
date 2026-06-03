# include<iostream>
# include<stack>
using namespace std;

// 递归排序栈

// 0. 计算栈中的元素个数 n = s.size()
// 1. 先递归访问栈中所有元素，得到和最大值max；a(n)
// 2. 再次递归访问栈中所有元素，得到最大值max有多少个；b(n, max)
// 3. 将max压入栈底，同时保证其余元素的相对次序不变；c(n, max, count)
// 4. 访问剩余元素 a(n-count)

// 1. 递归得到栈顶n个元素的最大值
int get_max(stack<int>& stk, int n) {
    if (n == 1) return stk.top();

    int top = stk.top();
    stk.pop();

    int ans = max(top, get_max(stk, n-1));
    stk.push(top);
    return ans;
}

// 2. 计算最大值的个数
int get_max_count(stack<int>& stk, int n, int max) {
    if (n == 0) return 0;

    int top = stk.top();
    stk.pop();

    int ans = top == max ? 1 : 0;
    ans += get_max_count(stk, n-1, max);
    stk.push(top);

    return ans;
}

// 3. 将max压入栈底，同时保证其余元素的相对次序不变
void push_max(stack<int>& stk, int n, int max, int max_count) {
    if (n == 0) {
        while (max_count--)
            stk.push(max);
    }

    else {
        int top = stk.top();
        stk.pop();

        push_max(stk, n-1, max, max_count);

        if (top != max)
            stk.push(top);
    }
}

// 4. 组装所有函数
void sortStack(stack<int>& stk) {
    int n = stk.size();
    while (n > 0) {
        int max = get_max(stk, n);
        int count = get_max_count(stk, n, max);
        push_max(stk, n, max, count);
        n -= count;
    }
}
