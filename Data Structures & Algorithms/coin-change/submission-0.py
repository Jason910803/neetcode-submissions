class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = [-1] * (amount + 1)

        def dfs(i):
            if i < 0:
                return float("inf")

            if i == 0:
                return 0

            if memo[i] != -1:
                return memo[i] 
            
            res = min(dfs(i - coin) + 1 for coin in coins)
            memo[i] = res
            return res
        
        return dfs(amount) if dfs(amount) != float("inf") else -1