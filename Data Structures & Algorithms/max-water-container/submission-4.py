class Solution:
    def maxArea(self, heights: List[int]) -> int:
        # return self.bruteforce(heights)
        return self.twoPointer(heights)

    def bruteforce(self, heights):
        n = len(heights)
        max_area = 0

        for left in range(n - 1):
            for right in range(left + 1, n):
                current_area = min(heights[left], heights[right]) * (right - left)
                max_area = max(max_area, current_area)
        
        return max_area
    
    def twoPointer(self, heights):
        left, right = 0, len(heights) - 1
        max_area = 0

        while left < right:
            current_area = min(heights[left], heights[right]) * (right - left)
            max_area = max(max_area, current_area)

            if heights[left] <= heights[right]:
                left += 1
            else:
                right -= 1
        
        return max_area