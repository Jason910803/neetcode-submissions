class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        memo = [-1] * n

        def dfs(i):
            if i >= n:
                return 0
            
            if memo[i] != -1:
                return memo[i]
            
            one_step = cost[i] + dfs(i + 1)
            two_step = cost[i] + dfs(i + 2)

            memo[i] = min(one_step, two_step)
            return memo[i]
        
        return min(dfs(0), dfs(1))