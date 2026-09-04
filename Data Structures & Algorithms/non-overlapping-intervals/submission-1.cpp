class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(),
            intervals.end(),
            [](const auto& a, const auto& b) {
                return a[1] < b[1];
            }
        );

        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int finish = intervals[i][1];

            if (start >= end) {
                end = finish;
            } else {
                count++;
            }
        }

        return count;
    }
};