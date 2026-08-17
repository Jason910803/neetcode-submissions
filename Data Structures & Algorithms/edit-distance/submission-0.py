class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1, n2 = len(word1), len(word2)
        memo = {} # (i, j) -> min ops for word1[i:] to word2[j:]

        # dfs(i, j) means minimum operations to convert word1[i:] to word2[j:]
        def dfs(i: int, j: int) -> int:
            if (i, j) in memo:
                return memo[(i, j)]
            
            # if word1 is exhausted, insert all remaining word2 chars
            if i == n1:
                return n2 - j
            
            # Conversely, the same applies
            if j == n2:
                return n1 - i
            
            if word1[i] == word2[j]:
                ans = dfs(i + 1, j + 1)
            else:
                insert_cost = 1 + dfs(i, j + 1)
                delete_cost = 1 + dfs(i + 1, j)
                replace_cost = 1 + dfs(i + 1, j + 1)
                ans = min(insert_cost, delete_cost, replace_cost)
            
            memo[(i, j)] = ans
            return ans
        
        return dfs(0, 0)