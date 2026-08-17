class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        nums.sort()

        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            j, k = i + 1, n - 1
            target = -nums[i]

            while j < k:
                current = nums[j] + nums[k]
                if current == target:
                    res.append([nums[i], nums[j], nums[k]])

                    while j < n - 1 and nums[j + 1] == nums[j]:
                        j += 1

                    j += 1
                elif current < target:
                    j += 1
                else:
                    k -= 1
        
        return res