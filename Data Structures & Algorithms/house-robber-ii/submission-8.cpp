class Solution {
private:
    int solve1(const vector<int>& nums, vector<int>& memo, int i, int end) {
        if (i > end) return 0;

        if (memo[i] != -1) return memo[i];

        int rob = nums[i] + solve1(nums, memo, i + 2, end);
        int not_rob = solve1(nums, memo, i + 1, end);
        return memo[i] = max(rob, not_rob);
    }

    int solve2(const vector<int>& nums, int start, int end) {
        int next1 = 0;
        int next2 = 0;

        for (int i = end; i >= start; i--) {
            int curr = max(nums[i] + next2, next1);
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // vector<int> memo1(n, -1);
        // int case1 = solve1(nums, memo1, 0, n - 2);

        // vector<int> memo2(n, -1);
        // int case2 = solve1(nums, memo2, 1, n - 1);

        // return max(case1, case2);

        return max(solve2(nums, 0, n - 2),
                   solve2(nums, 1, n - 1));
    }
};
