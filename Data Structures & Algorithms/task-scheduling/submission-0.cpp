class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freqCount[26] = {0};
        for (int task : tasks) {
            freqCount[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int freq : freqCount) {
            if (freq) {
                maxHeap.push(freq);
            }
        }

        int ans = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;

            for (int i = 0; i < n + 1; i++) {
                if (maxHeap.empty()) {
                    if (temp.empty()) {
                        ans += i;
                        return ans;
                    }
                    break;
                }

                int freq = maxHeap.top() - 1;
                maxHeap.pop();
                if (freq) {
                    temp.push_back(freq);
                }
            }

            ans += n + 1;
            for (int freq : temp) {
                maxHeap.push(freq);
            }
        }

        return ans;
    }
};
