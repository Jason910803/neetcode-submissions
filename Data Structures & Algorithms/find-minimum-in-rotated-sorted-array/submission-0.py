class Solution:
    def findMin(self, nums: List[int]) -> int:
        min_element = float("inf")

        for num in nums:
            if num < min_element:
                min_element = num
        
        return min_element
        