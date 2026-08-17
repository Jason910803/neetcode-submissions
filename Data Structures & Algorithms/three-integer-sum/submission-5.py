class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        return self.method1(nums)

    def method1(self, nums):
        nums.sort()
        # [-4, -1, -1, 0, 1, 2]
        res = []
        n = len(nums)

        for i in range(n - 2):
            # deduplication for the first num
            if i > 0 and nums[i - 1] == nums[i]:
                continue
                
            left, right = i + 1, n - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]

                if total > 0:
                    # shift the right pointer left
                    right -= 1
                elif total < 0:
                    # shift the left pointer right
                    left += 1
                else:
                    res.append([nums[i], nums[left], nums[right]])
                    # deduplication
                    while left < right and nums[left + 1] == nums[left]:
                        left += 1
                    while left < right and nums[right - 1] == nums[right]:
                        right -= 1
                    
                    left += 1
                    right -= 1
        
        return res