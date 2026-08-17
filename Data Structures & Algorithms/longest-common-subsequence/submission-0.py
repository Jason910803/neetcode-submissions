class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n, m = len(text1), len(text2)
        memo = [[-1] * n for _ in range(m)]

        def dfs(i, j):
            if i not in range(m) or j not in range(n):
                return 0
            
            if memo[i][j] != -1:
                return memo[i][j]
            
            if text2[i] == text1[j]:
                res = 1 + dfs(i + 1, j + 1)
            else:
                res = max(dfs(i, j + 1), dfs(i + 1, j))
            
            memo[i][j] = res
            return res
        
        return dfs(0, 0)