class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() >= 2) {
            int first = maxHeap.top(); maxHeap.pop();
            int second = maxHeap.top(); maxHeap.pop();

            int remain = first - second;
            if (remain) {
                maxHeap.push(remain);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};