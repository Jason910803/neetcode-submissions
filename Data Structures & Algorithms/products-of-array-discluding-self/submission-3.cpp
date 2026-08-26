class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        return sol1(nums);
    }

    vector<int> sol1(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> result(n);

        // traverse the left array
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // traverse the right array
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};
