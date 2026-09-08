class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 1);

        // int ans = 1;
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[j] < nums[i]) {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }

        //     ans = max(ans, dp[i]);
        // }

        // return ans;

        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);

            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }

        return tails.size();
    }
};