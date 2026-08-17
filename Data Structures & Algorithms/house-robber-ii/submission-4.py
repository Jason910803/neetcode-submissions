class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        def solve(arr):
            memo = [-1] * len(arr)

            def dfs(i):
                if i >= len(arr):
                    return 0
                
                if memo[i] != -1:
                    return memo[i]
                
                memo[i] = max(dfs(i + 1), arr[i] + dfs(i + 2))
                return memo[i]
            
            return dfs(0)
        
        return max(solve(nums[1:]), solve(nums[:-1]))