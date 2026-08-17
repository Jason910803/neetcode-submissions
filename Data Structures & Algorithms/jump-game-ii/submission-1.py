class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        INF = 10**9
        memo = [-1] * n

        def dfs(i):
            if i >= n - 1:
                return 0
            if nums[i] == 0:
                return INF
            if memo[i] != -1:
                return memo[i]
            
            best = INF
            far = min(n - 1, i + nums[i])
            for j in range(i + 1, far + 1):
                best = min(best, 1 + dfs(j))
            
            memo[i] = best
            return best

        ans = dfs(0)
        return ans