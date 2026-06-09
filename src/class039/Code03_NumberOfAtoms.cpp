# include<iostream>
# include<string>
# include<vector>
# include<unordered_map>
# include<algorithm>
using namespace std;

// 含有嵌套的分子式求原子数量
// 测试链接 : https://leetcode.cn/problems/number-of-atoms/

// 需要注意的点：
// 1. 元素一定以大写字母开头且有且仅有一个大写字母，因此每次访问到大写字母时将元素名和计数上传并清空；
// 2. 如果元素名不为空且计数为0，说明当前分子式只有一个该元素，要将计数改为1再上传；
// 3. 同理，在一个子式访问完毕后，如果times为0，说明这个子式只有一个，要将times改为1.

class Solution {
public:
    string countOfAtoms(string formula) {
        int cur = 0;
        unordered_map<string, int> atoms = subCount(formula, cur);
        vector<string> atomsDict;
        string ans;
        for (auto [k, v]: atoms) {
            atomsDict.push_back(k);
        }

        sort(atomsDict.begin(), atomsDict.end());
        for (auto atom: atomsDict) {
            ans += atom;
            string num = to_string(atoms[atom]);
            if (num != "0" && num != "1")
                ans += num;
        }

        return ans;
    }

    unordered_map<string, int> subCount(string formula, int& cur) {
        string cur_atom;
        int cur_num = 0;
        unordered_map<string, int> result;
        while (cur < formula.size()) {
            char c = formula[cur];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                if (c >= 'A' && c <= 'Z') {
                    if (cur_atom != "") {
                        cur_num = cur_num == 0 ? 1 : cur_num;
                        if (result.find(cur_atom) == result.end())
                            result[cur_atom] = cur_num;
                        else
                            result[cur_atom] += cur_num;
                        cur_atom = "";
                        cur_num = 0;
                    }
                }
                cur_atom += c;
                cur++;
            }
            else if (c >= '0' && c <= '9') {
                cur_num = cur_num * 10 + c - '0';
                cur++;
            }
            else {
                if (c == '(') {
                    cur++;
                    unordered_map<string, int> sub = subCount(formula, cur);
                    for (auto& [k, v]: sub) {
                        if (result.find(k) == result.end())
                            result[k] = v;
                        else
                            result[k] += v;
                    }
                }
                else if (c == ')'){
                    cur++;
                    if (cur_atom != "") {
                        cur_num = cur_num == 0 ? 1 : cur_num;
                        if (result.find(cur_atom) == result.end())
                            result[cur_atom] = cur_num;
                        else
                            result[cur_atom] += cur_num;
                    }
                    int times = 0;
                    while (formula[cur] >= '0' && formula[cur] <= '9') {
                        times = times * 10 + formula[cur] - '0';
                        cur++;
                    }
                    if (times == 0) times = 1;
                    for (auto& [k, v]: result)
                        v *= times;

                    return result;
                }
                else ;
            }
        }
        if (cur_atom != "") {
            cur_num = cur_num == 0 ? 1 : cur_num;
            if (result.find(cur_atom) == result.end())
                result[cur_atom] = cur_num;
            else
                result[cur_atom] += cur_num;
        }
        return result;
    }
};
