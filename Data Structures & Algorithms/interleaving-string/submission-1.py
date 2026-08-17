class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n1 + n2 != n3:
            return False
        
        memo = {} # (i, j) -> bool

        def dfs(i: int, j: int) -> bool:
            if (i, j) in memo:
                return memo[(i, j)]

            k = i + j # index in s3

            # If we've consumed both s1 and s2, we've formed all of s3
            if i == n1 and j == n2:
                return True
            
            ok = False

            # Option 1: take next char from s1
            if i < n1 and s3[k] == s1[i]:
                ok = dfs(i + 1, j)
            
            # Option 2: take next char from s2 (only if not already ok)
            if not ok and j < n2 and s3[k] == s2[j]:
                ok = dfs(i, j + 1)
            
            memo[(i, j)] = ok
            return ok
        
        return dfs(0, 0)