class Solution {
private:
    int global_max = INT_MIN;

    pair<int, int> solve(
        const vector<int>& nums,
        vector<pair<int, int>>& memo,
        vector<bool>& visited,
        int i
    ) {
        if (i == nums.size() - 1) {
            global_max = max(global_max, nums[i]);
            return {nums[i], nums[i]};
        }

        if (visited[i]) {
            return memo[i];
        }

        pair<int, int> next = solve(nums, memo, visited, i + 1);
        int curr_max = max({nums[i], nums[i] * next.first, nums[i] * next.second});
        int curr_min = min({nums[i], nums[i] * next.first, nums[i] * next.second});

        global_max = max(global_max, curr_max);
        visited[i] = true;

        return memo[i] = {curr_max, curr_min};
    }

public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> memo(nums.size(), pair<int, int>{0, 0});
        vector<bool> visited(nums.size(), false);

        solve(nums, memo, visited, 0);
        return global_max;
    }
};
