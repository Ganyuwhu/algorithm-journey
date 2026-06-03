# include<iostream>
# include<vector>
# include <algorithm>
using namespace std;

// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的组合
// 答案 不能 包含重复的组合。返回的答案中，组合可以按 任意顺序 排列
// 注意其实要求返回的不是子集，因为子集一定是不包含相同元素的，要返回的其实是不重复的组合
// 比如输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 测试链接 : https://leetcode.cn/problems/subsets-ii/


// 1. 数组返回子集与字符串返回子串不同，数组返回子集只考虑重复元素的数量，但字符串返回子串可以通过重复元素的位置进行区分
// 2. 因此可以先进行排序，将重复元素集中到一起，然后根据重复元素的数目来构建子集
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans = vector<vector<int>>();
        path = vector<int>();
        sort(nums.begin(), nums.end());
        dfs(nums, 0);

        return ans;
    }

    void dfs(vector<int>& nums, int start) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            // 下面if语句的作用是进行相同元素去重，只将start处的元素压入path，后续所有与start处相同的元素都被跳过，但它们会在38行处的递归中被压入
            if (i > start && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
};