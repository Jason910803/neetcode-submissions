class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        memo = {}

        def dfs(i: int, cur_sum: int) -> int:
            if i == n or cur_sum > amount:
                return 0
            
            if cur_sum == amount:
                return 1
            
            if (i, cur_sum) in memo:
                return memo[(i, cur_sum)]
            
            # choose coins[i]
            res = dfs(i, cur_sum + coins[i])

            # skip coins[i]
            res += dfs(i + 1, cur_sum)
            
            memo[(i, cur_sum)] = res
            return res
        
        return dfs(0, 0)