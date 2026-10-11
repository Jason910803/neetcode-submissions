class Solution {
private:
    vector<vector<int>> memo;

    bool dfs(vector<int>& nums, int index, int target) {
        if (target == 0) {
            return true;
        }

        if (index == nums.size() || target < 0) {
            return false;
        }

        if (memo[index][target] != -1) {
            return memo[index][target] == 1;
        }

        // not choose or choose
        bool result = dfs(nums, index + 1, target) || dfs(nums, index + 1, target - nums[index]);
        memo[index][target] = result ? 1 : 0;
        
        return result;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2) {
            return false;
        }

        int target = sum / 2;
        memo.assign(nums.size(), vector<int>(target + 1, -1));
        
        return dfs(nums, 0, target);
    }
};
