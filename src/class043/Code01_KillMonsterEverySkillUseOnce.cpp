# include<iostream>
# include<vector>
# include<climits>
using namespace std;

// 现在有一个打怪类型的游戏，这个游戏是这样的，你有n个技能
// 每一个技能会有一个伤害，
// 同时若怪物小于等于一定的血量，则该技能可能造成双倍伤害
// 每一个技能最多只能释放一次，已知怪物有m点血量
// 现在想问你最少用几个技能能消灭掉他(血量小于等于0)
// 技能的数量是n，怪物的血量是m
// i号技能的伤害是x[i]，i号技能触发双倍伤害的血量最小值是y[i]
// 1 <= n <= 10
// 1 <= m、x[i]、y[i] <= 10^6
// 测试链接 : https://www.nowcoder.com/practice/d88ef50f8dab4850be8cd4b95514bbbd

int count_skill(vector<int> damage, vector<int> threshold, int blood, int& mininum) {
    int count = 0;
    while (count < damage.size()) {
        int this_threshold = threshold[count];
        int this_damage = blood <= this_threshold ? 2 * damage[count] : damage[count];
        blood -= this_damage;
        count++;
        if (blood <= 0)
            break;
    }
    if (blood > 0)
        return mininum;
    return count;
}

// 全排列函数
void backtrack(vector<int>& damage, vector<int>& threshold, int start, int blood, int& mininum){
    // 到终点时计算一次要使用的技能数，若小于当前最小值则更新
    if (start == damage.size()) {
        int count = count_skill(damage, threshold, blood, mininum);
        mininum = count < mininum ? count : mininum;
        return;
    }

    for (int i = start; i < damage.size(); i++) {
        swap(damage[i], damage[start]);
        swap(threshold[i], threshold[start]);
        backtrack(damage, threshold, start+1, blood, mininum);
        swap(damage[i], damage[start]);
        swap(threshold[i], threshold[start]);
    }
}

// int main() {
//     int T = 0;
//     cin >> T;
//
//     int exp = 0;
//     while (exp < T) {
//         int n = 0; int m = 0;
//         cin >> n >> m;
//         vector<int> damage;
//         vector<int> threshold;
//         int count = 0;
//         int A; int x;
//         while (count < n) {
//             cin >> A >> x;
//             damage.push_back(A);
//             threshold.push_back(x);
//             count++;
//         }
//         int mininum = n+1;
//         backtrack(damage, threshold, 0, m, mininum);
//         int output = mininum == n+1 ? -1 : mininum;
//         cout << output << endl;
//         exp++;
//     }
//     return 0;
// }