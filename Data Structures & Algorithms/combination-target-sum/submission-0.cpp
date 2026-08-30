class Solution {
public:
    void backtrack(
        int start, 
        vector<int>& nums, 
        int target,
        vector<int>& path,
        vector<vector<int>>& ans
    ) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(i, nums, target - nums[i], path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(0, nums, target, path, ans);

        return ans;
    }
};
