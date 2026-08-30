class Solution {
public:
    void backtrack(
        unordered_set<int>& used,
        const vector<int>& nums,
        vector<int>& path,
        vector<vector<int>>& ans
    ) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used.count(nums[i])) {
                continue;
            }

            used.insert(nums[i]);
            path.push_back(nums[i]);

            backtrack(used, nums, path, ans);

            path.pop_back();
            used.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> used;
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(used, nums, path, ans);

        return ans;
    }
};
