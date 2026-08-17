class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        n = len(piles)

        def canFinish(rate):
            count = 0
            for i in range(n):
                count += math.ceil(piles[i] / rate)
            
            return count <= h
        
        left, right = 1, max(piles)

        while left <= right:
            mid = (left + right) // 2

            if canFinish(mid):
                right = mid - 1
            else:
                left = mid + 1
        
        return left