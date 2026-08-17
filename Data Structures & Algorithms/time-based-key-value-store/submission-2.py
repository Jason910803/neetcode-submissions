class TimeMap:

    def __init__(self):
        self.mp = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.mp[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.mp:
            return ""
        
        left, right = 0, len(self.mp[key]) - 1
        while left <= right:
            mid = (left + right) // 2

            if self.mp[key][mid][0] <= timestamp:
                left = mid + 1
            else:
                right = mid - 1
        
        if right < 0:
            return ""

        return self.mp[key][right][1]