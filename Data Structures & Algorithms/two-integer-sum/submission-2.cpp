class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // {value : index}
        unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            int remain = target - value;

            auto it = index.find(remain);
            if (it != index.end()) {
                return {it->second, i};
            }

            index[value] = i;
        }
    }
};
