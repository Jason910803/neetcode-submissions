class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        def at_most(x):
            if x < 0:
                return 0
            
            left = cur = ans = 0
            for right, num in enumerate(nums):
                cur += num
                while cur > x:
                    cur -= nums[left]
                    left += 1
                ans += (right - left + 1)
            
            return ans
        
        return at_most(goal) - at_most(goal - 1)