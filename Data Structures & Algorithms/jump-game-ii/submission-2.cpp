class Solution {
private:
    int solve(const vector<int>& nums, vector<int>& memo, int i) {
        if (i == 0) return 0;
        if (memo[i] != -1) return memo[i];

        memo[i] = 1e9;
        for (int j = i - 1; j >= 0; j--) {
            if (j + nums[j] >= i) {
                memo[i] = min(memo[i], solve(nums, memo, j) + 1);
            }
        }

        return memo[i];
    }

public:
    int jump(vector<int>& nums) {
        // vector<int> memo(nums.size(), -1);
        // return solve(nums, memo, nums.size() - 1);

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};