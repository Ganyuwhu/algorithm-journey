# include<iostream>
# include<vector>
# include <algorithm>
using namespace std;

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
            if (i > start && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
};
