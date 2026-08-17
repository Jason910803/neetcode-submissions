class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curMax, curMin = 1, 1
        res = nums[0]

        for num in nums:
            temp = curMax * num
            curMax = max(temp, curMin * num, num)
            curMin = min(temp, curMin * num, num)
            res = max(res, curMax)
        
        return res