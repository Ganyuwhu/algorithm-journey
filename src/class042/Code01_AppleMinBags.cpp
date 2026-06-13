# include<iostream>
using namespace std;

class Code01_AppleMinBags {
    static int nums(int bought) {
        if (bought % 2 == 1)
            return -1;
        if (bought <= 14) {
            if (bought == 6 || bought == 8)
                return 1;
            if (bought == 12 || bought == 14)
                return 2;
            return -1;
        }
        if (bought % 8 == 0)
            return bought / 8;
        return bought / 8 + 1;
    }

    static int solution() {
        int bought = 0;
        cin >> bought;
        cout << nums(bought);
    }

    // 重要的在于如何通过暴力递归寻找规律
    static int f(int bought) {
        if (bought < 0)
            return INT_MAX;
        if (bought == 0)
            return 0;
        int p1 = f(bought - 8);
        int p2 = f(bought - 6);
        p1 += p1 != INT_MAX ? 1 : 0;
        p2 += p2 != INT_MAX ? 1 : 0;
        return min(p1, p2);
    }

    static void bags(int bought) {
        int nums = f(bought) == INT_MAX ? -1 : f(bought);
        cout << bought << " " << nums << endl;
    }

    static void print() {
        int i = 0;
        while(i < 100) {
            bags(i);
            i++;
        }
    }
};