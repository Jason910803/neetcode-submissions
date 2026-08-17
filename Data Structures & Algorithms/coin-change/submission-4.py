class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        # memo = [[-1] * (amount + 1) for _ in range(n)]

        # def dfs(i, c):
        #     if i < 0:
        #         return 0 if c == 0 else amount + 1
            
        #     if memo[i][c] != -1:
        #         return memo[i][c]

        #     if c < coins[i]:
        #         res = dfs(i - 1, c)
        #     else:
        #         res = min(dfs(i - 1, c), 1 + dfs(i, c - coins[i]))
            
        #     memo[i][c] = res
        #     return res
        
        # ans = dfs(n - 1, amount)
        # return ans if ans != amount + 1 else -1

        dp = [[amount + 1] * (amount + 1) for _ in range(2)]
        dp[0][0] = 0

        for i in range(n):
            for c in range(amount + 1):
                if c < coins[i]:
                    dp[(i + 1) % 2][c] = dp[i % 2][c]
                else:
                    dp[(i + 1) % 2][c] = min(dp[i % 2][c], 1 + dp[(i + 1) % 2][c - coins[i]])
        
        ans = dp[n % 2][amount] 
        return ans if ans < amount + 1 else -1