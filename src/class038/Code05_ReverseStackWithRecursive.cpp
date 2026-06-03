# include<iostream>
# include<stack>
using namespace std;

// 用递归函数逆序栈

class Solution {
public:
    static int bottomOut(stack<int>& st);
    static void reverse(stack<int>& st);
    static void reverse_stack(int size);
};

int Solution::bottomOut(stack<int>& st) {
    int ans = st.top();
    st.pop();

    if (st.empty()) {
        return ans;
    }
    int last = bottomOut(st);
    st.push(ans);
    return last;
}

void Solution::reverse(stack<int>& st) {
    if (st.empty()) return;
    int last = bottomOut(st);
    reverse(st);
    st.push(last);
}

void Solution::reverse_stack(int size) {
    int deep = 0;
    stack<int> st;
    while (deep < size) {
        int num = rand () % 10;
        st.push(num);
        deep++;
    }
    stack<int> reversed = st;
    reverse(reversed);

    cout << "原栈" << " " << "反转后" << endl;
    while (!st.empty()) {
        int st_num = st.top();
        int reversed_num = reversed.top();
        st.pop();
        reversed.pop();
        cout << st_num << " " << reversed_num << endl;
    }
}
