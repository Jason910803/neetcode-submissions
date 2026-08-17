class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)

        memo = {}
        # dfs(left, right) means maximum coins you can get by bursting all ballons strictly between left and right
        def dfs(left, right):
            if left + 1 == right:
                return 0
            
            if (left, right) in memo:
                return memo[(left, right)]
            
            best = 0
            for i in range(left + 1, right):
                coins = nums[left] * nums[i] * nums[right]
                total = dfs(left, i) + coins + dfs(i, right)
                best = max(best, total)
            
            memo[(left, right)] = best
            return best
        
        return dfs(0, n - 1)
