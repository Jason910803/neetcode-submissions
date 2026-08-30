class Solution {
public:
    void backtrack(
        const vector<int>& nums,
        vector<int>& path,
        vector<vector<int>>& ans,
        int start
    ) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, path, ans, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(nums, path, ans, 0);

        return ans;
    }
};
