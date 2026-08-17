class Solution:
    def maxArea(self, heights: List[int]) -> int:
        n = len(heights)
        l, r = 0, n - 1
        left, right = heights[l], heights[r]
        res = 0

        while l < r:
            amount = min(left, right) * (r - l)
            res = max(res, amount)

            if left < right:
                l += 1
                left = heights[l]
            else:
                r -= 1
                right = heights[r]
        
        return res