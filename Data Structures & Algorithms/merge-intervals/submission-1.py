class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []

        intervals.sort(key=lambda x: x[0])

        res = []
        prevStart, prevEnd = intervals[0][0], intervals[0][1]

        for start, end in intervals[1:]:
            if start <= prevEnd:
                prevEnd = max(prevEnd, end)
            else:
                res.append([prevStart, prevEnd])
                prevStart = start
                prevEnd = end
        
        res.append([prevStart, prevEnd])

        return res