
// https://leetcode.cn/problems/permutations-ii/
// 47. 全排列 II

class Solution {
    vector<int> path;
    vector<vector<int>> ret;
    bool check[9];

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int pos) {
        if (pos == nums.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // if (check[i] == true ||
            //     (i != 0 && nums[i] == nums[i - 1] && check[i - 1] == false))
            //     { continue;
            // }
            if (check[i] == false &&
                (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == true)) {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums, pos + 1);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};