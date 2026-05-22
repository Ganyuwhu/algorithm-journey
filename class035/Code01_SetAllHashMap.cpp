#include <iostream>
#include <unordered_map>
using namespace std;

// 创建支持setAll的哈希表
// 测试链接：https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967

class HashMap {
private:
    unordered_map<int, pair<int, int>> map;
    int currentTime = 0;
    int setAllValue = 0;
    int setAllTime = -1;

public:
    void put(int key, int value) {
        map[key] = {value, currentTime++};
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        else {
            int value = map[key].first;
            int setTime = map[key].second;
            value = setTime > setAllTime ? value : setAllValue;
            return value;
        }
    }

    void setAll(int value) {
        setAllValue = value;
        setAllTime = currentTime++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0;
    cin >> N;

    int opt = 0, x = 0, y = 0;

    HashMap myMap;

    while (N--) {
        cin >> opt;
        if (opt == 1) {
            cin  >> x >> y;
            myMap.put(x, y);
        }
        else if (opt == 2) {
            cin >> x;
            cout << myMap.get(x) << endl;
        }
        else if (opt == 3) {
            cin >> x;
            myMap.setAll(x);
        }
        else;
    }
}
// 64 位输出请用 printf("%lld")