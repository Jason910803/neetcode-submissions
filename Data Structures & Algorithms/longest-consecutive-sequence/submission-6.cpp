class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int result = 0;

        for (int num : numSet) {
            if (numSet.count(num - 1)) continue;

            int length = 1;
            int currentNum = num;
            while (numSet.count(currentNum + 1)) {
                length++;
                currentNum++;
            }

            result = max(result, length);
        }

        return result;
    }
};
