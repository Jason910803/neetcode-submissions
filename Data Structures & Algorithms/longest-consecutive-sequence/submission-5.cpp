class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int result = 0;

        for (int num : nums) {
            if (numSet.count(num - 1)) continue;

            int length = 1;
            while (numSet.count(num + 1)) {
                length++;
                num++;
            }

            result = max(result, length);
        }

        return result;
    }
};
