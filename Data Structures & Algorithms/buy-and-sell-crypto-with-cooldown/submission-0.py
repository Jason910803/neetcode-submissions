class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        memo = [[-1] * 2 for _ in range(n)]

        def dfs(i, holding):
            if i >= n:
                return 0
            
            if memo[i][holding] != -1:
                return memo[i][holding]
            
            # if holding == 0, we can buy or skip
            if holding == 0:
                # buy or skip
                res = max(dfs(i + 1, 1) - prices[i], dfs(i + 1, 0))
            # if holding == 1, we can sell or skip
            else:
                # sell or skip
                res = max(dfs(i + 2, 0) + prices[i], dfs(i + 1, 1))

            memo[i][holding] = res
            return res
        
        return dfs(0, 0)
            