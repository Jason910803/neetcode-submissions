class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []

        for i in range(len(intervals)):
            start = intervals[i][0]
            end = intervals[i][1]

            if end < newInterval[0]:
                res.append([start, end])
            elif newInterval[1] < start:
                res.append(newInterval)
                return res + intervals[i:]
            else:
                newInterval = [
                    min(start, newInterval[0]),
                    max(end, newInterval[1])
                ]
        
        res.append(newInterval)
        return res