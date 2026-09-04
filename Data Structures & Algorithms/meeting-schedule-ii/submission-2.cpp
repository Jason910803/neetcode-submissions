/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
private:
    int method1(vector<Interval>& intervals) {
        // sorting + minHeap
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ans = 0;

        for (const auto& interval : intervals) {
            while (!minHeap.empty() && interval.start >= minHeap.top()) {
                minHeap.pop();
            }

            minHeap.push(interval.end);

            ans = max(ans, static_cast<int>(minHeap.size()));
        }

        return ans;
    }

public:
    int minMeetingRooms(vector<Interval>& intervals) {
        return method1(intervals);
    }
};
