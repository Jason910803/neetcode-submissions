class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return sol2(nums, k);
    }

    vector<int> sol2(vector<int>& nums, int k) {
        // bucket sort
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, freq] : count) {
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for (int i = nums.size(); i >= 1; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
    }

    vector<int> sol1(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (const auto& [num, freq] : count) {
            minHeap.push({freq, num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        result.reserve(k);

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
