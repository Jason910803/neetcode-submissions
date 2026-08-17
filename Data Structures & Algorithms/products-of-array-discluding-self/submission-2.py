class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # n = len(nums)
        # left, right, ans = [0] * n, [0] * n, [0] * n

        # left[0] = 1
        # for i in range(1, n):
        #     left[i] = nums[i - 1] * left[i - 1]
        
        # right[n - 1] = 1
        # for i in range(n - 2, -1, -1):
        #     right[i] = nums[i + 1] * right[i + 1]
        
        # for i in range(n):
        #     ans[i] = left[i] * right[i]
    
        # return ans

        # Time: O(N), Space: O(N)

        n = len(nums)
        # use ans array to store the left product
        ans = [0] * n
        ans[0] = 1
        for i in range(1, n):
            ans[i] = nums[i - 1] * ans[i - 1]

        right = 1
        for i in range(n - 1, -1, -1):
            ans[i] = ans[i] * right
            right *= nums[i]
        
        return ans