class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int result = 0;

        for (int num : nums) {
            if (st.count(num - 1)) continue;

            int length = 1;
            while (st.count(num + 1)) {
                length++;
                num++;
            }

            result = max(result, length);
        }

        return result;
    }
};
