
//https://leetcode.cn/problems/combination-sum/
// 39. 组合总和

class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    int aim;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        aim = target;
        dfs(candidates, 0, 0);
        return ret;
    }

    void dfs(vector<int>& candidates, int pos, int sum) {
        if (sum == aim) {
            ret.push_back(path);
            return;
        }
        if (pos == candidates.size() || sum > aim)
            return;

        for (int i = pos; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i]);
            path.pop_back();
        }
    }
};