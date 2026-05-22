# include<iostream>
# include<unordered_map>
# include<vector>
using namespace std;

// O(1)时间复杂度随机增删查
// 测试链接：https://leetcode.cn/problems/insert-delete-getrandom-o1/

class RandomizedSet {
private:
    unordered_map<int, int> hashMap;
    vector<int> array;

public:
    RandomizedSet() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        if (hashMap.find(val) == hashMap.end()) {
            hashMap.insert({val, array.size()});
            array.push_back(val);
            return true;
        }
        else
            return false;
    }

    bool remove(int val) {
        if (hashMap.find(val) == hashMap.end())
            return false;
        else {
            int index = hashMap[val];
            if (index != array.size()-1) {
                int last_val = array[array.size()-1];
                array[index] = last_val;
                hashMap[last_val] = index;
            }
            hashMap.erase(val);
            array.pop_back();
            return true;
        }
    }

    int getRandom() {
        int randomIdx = rand() % array.size();
        return array[randomIdx];
    }
};