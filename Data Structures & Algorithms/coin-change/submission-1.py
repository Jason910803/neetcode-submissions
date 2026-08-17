class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        memo = [[-1] * (amount + 1) for _ in range(n)]

        def dfs(i, c):
            if i < 0:
                return 0 if c == 0 else amount + 1
            
            if memo[i][c] != -1:
                return memo[i][c]

            if c < coins[i]:
                res = dfs(i - 1, c)
            else:
                res = min(dfs(i - 1, c), 1 + dfs(i, c - coins[i]))
            
            memo[i][c] = res
            return res
        
        ans = dfs(n - 1, amount)
        return ans if ans != amount + 1 else -1