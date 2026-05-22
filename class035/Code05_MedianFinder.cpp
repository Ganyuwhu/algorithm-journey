# include<iostream>
# include<queue>
using namespace std;

// 快速寻找数组中位数
// 测试链接：https://leetcode.cn/problems/find-median-from-data-stream/description/

class MedianFinder {
private:
    priority_queue<int, vector<int>, std::less<>> maxHeap;
    priority_queue<int, vector<int>, std::greater<>> lessHeap;

public:
    MedianFinder() = default;

    void addNum(int num) {
        if (maxHeap.size() <= lessHeap.size())
            maxHeap.push(num);

        else {
            lessHeap.push(num);
        }

        if (lessHeap.size() > 0 && maxHeap.top() > lessHeap.top()) {
            int max_top = maxHeap.top();
            int less_top = lessHeap.top();
            maxHeap.pop();
            lessHeap.pop();
            lessHeap.push(max_top);
            maxHeap.push(less_top);
        }
    }

    double findMedian() {
        if (maxHeap.size() > lessHeap.size())
            return static_cast<double>(maxHeap.top());
        else if (maxHeap.size() < lessHeap.size())
            return static_cast<double>(lessHeap.top());
        else {
            double max_top = static_cast<double>(maxHeap.top());
            double less_top = static_cast<double>(lessHeap.top());
            return (max_top + less_top) / 2;
        }
    }
};