class Solution {
private:
    int solve(const vector<int>& nums, vector<int>& memo, int i) {
        if (i >= nums.size()) return 0;

        if (memo[i] != -1) return memo[i];

        int rob = nums[i] + solve(nums, memo, i + 2);
        int not_rob = solve(nums, memo, i + 1);
        return memo[i] = max(rob, not_rob);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, memo, 0);
    }
};
