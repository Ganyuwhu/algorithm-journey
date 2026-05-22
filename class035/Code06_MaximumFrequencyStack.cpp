# include<iostream>
# include<unordered_map>
# include<stack>
# include<vector>
using namespace std;

// 创建最大频率栈
// 测试链接：https://leetcode.cn/problems/maximum-frequency-stack/

class FreqStack {
private:
    unordered_map<int, int> freqMap;
    vector<stack<int>> doubleStack;

public:
    FreqStack() = default;

    void push(int val) {
        int freq = freqMap.find(val) == freqMap.end() ? 1 : freqMap[val] + 1;
        // 2. 更新词频表
        if (freq == 1)
            freqMap.insert({val, freq});
        else
            freqMap[val] = freq;
        // 3. 将值插入到对应的队列中
        if (doubleStack.size() < freq) {
            doubleStack.push_back({});
            doubleStack[freq-1].push(val);
        }
        else
            doubleStack[freq-1].push(val);
    }

    int pop() {
        int top_val = doubleStack[doubleStack.size()-1].top();
        freqMap[top_val]--;
        if (freqMap[top_val] == 0)
            freqMap.erase(top_val);
        doubleStack[doubleStack.size()-1].pop();
        if (doubleStack[doubleStack.size()-1].size() == 0)
            doubleStack.pop_back();
        return top_val;
    }
};