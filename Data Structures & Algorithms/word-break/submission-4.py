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
                    res = dfs(i + len(word))
                    if res:
                        memo[i] = res
                        return res
            
            memo[i] = False
            return memo[i]
        
        return dfs(0)