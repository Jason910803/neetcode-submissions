class Solution {
private:
    int solve(const vector<int>& nums, vector<int>& memo, int i) {
        if (i == 0) return 1;
        if (memo[i] != -1) return memo[i];

        for (int j = i - 1; j >= 0; j--) {
            if (solve(nums, memo, j) && j + nums[j] >= i) {
                return memo[i] = 1;
            }
        }

        return memo[i] = 0;
    }

public:
    bool canJump(vector<int>& nums) {
        // vector<int> memo(nums.size(), -1);
        // return solve(nums, memo, nums.size() - 1) == 1;

        int max_reach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > max_reach) return false;

            max_reach = max(max_reach, i + nums[i]);

            if (max_reach >= n - 1) return true;
        }

        return true;
    }
};