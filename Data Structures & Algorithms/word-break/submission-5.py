class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        memo = {}

        def dfs(i):
            if i == n:
                return True
            
            if i in memo:
                return memo[i]
            
            for word in wordDict:
                if i + len(word) <= n and s[i : i + len(word)] == word:
                    if dfs(i + len(word)):
                        memo[i] = True
                        return True
            
            memo[i] = False
            return False
        
        return dfs(0)