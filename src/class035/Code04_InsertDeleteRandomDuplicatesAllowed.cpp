# include<iostream>
# include<vector>
# include<unordered_map>
# include<unordered_set>
using namespace std;

// O(1)时间复杂度随机增删查，允许重复
// 测试链接：https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> hashMap;
    vector<int> array;

public:
    RandomizedCollection() {
        srand(time(nullptr));  // 初始化随机种子
    }

    bool insert(int val) {
        bool notExist = hashMap.find(val) == hashMap.end();
        hashMap[val].insert(array.size());
        array.push_back(val);
        return notExist;
    }

    bool remove(int val) {
        auto it = hashMap.find(val);
        if (it == hashMap.end()) return false;

        int removeIdx = *it->second.begin();
        it->second.erase(removeIdx);

        if (removeIdx != array.size() - 1) {
            int lastVal = array.back();

            hashMap[lastVal].erase(array.size() - 1);
            hashMap[lastVal].insert(removeIdx);

            array[removeIdx] = lastVal;
        }

        array.pop_back();

        if (it->second.empty()) {
            hashMap.erase(it);
        }

        return true;
    }

    int getRandom() {
        int randomIdx = rand() % array.size();
        return array[randomIdx];
    }
};