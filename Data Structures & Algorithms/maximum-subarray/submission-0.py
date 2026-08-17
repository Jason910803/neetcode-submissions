class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prev = nums[0]
        res = nums[0]

        for num in nums[1:]:
            prev = max(num, num + prev)
            res = max(res, prev)
        
        return res