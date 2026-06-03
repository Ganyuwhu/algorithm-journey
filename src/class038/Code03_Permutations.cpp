# include<iostream>
# include<vector>
using namespace std;

// 没有重复项数字的全排列
// 测试链接 : https://leetcode.cn/problems/permutations/

class Solution {
public:
    vector<vector<int>> permutations;
    vector<vector<int>> permute(vector<int>& nums) {
        // 1. 全排列的思路是，逐位置确定元素，下一个位置的可选元素只能从尚未被确定的元素中选出；
        // 2. 例如，假设nums = [1, 2, 3]
        // 3. 将第一个元素确定为3，因此下一个可选元素只能从[1, 2]中选择
        // 4. 为了达到这种效果，可以将1和3进行交换，这样可以知道3及之前的元素都是已经确定好位置的，3之后的元素是还未确定的
        // 5. 随后继续确定第二个元素，第三个元素
        // 6. 每次交换后都要再交换回来以保证可以访问初始nums中的排序
        permutations = vector<vector<int>>();
        f(nums, 0);
        return permutations;
    }

    void f(vector<int>& nums, int i) {
        if (i == nums.size()) {
            permutations.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);  // 将第i个元素设置成nums的第j个元素
            f(nums, i+1);
            swap(nums[i], nums[j]);  // 复原，将nums重置成原数组
        }
    }
};
