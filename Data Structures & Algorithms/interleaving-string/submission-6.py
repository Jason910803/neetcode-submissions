class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n1 + n2 != n3:
            return False
        
        # dp[i][j] means can we form s3[i+j:] using s1[i:] and s2[j:] 
        dp = [False] * (n2 + 1)
        dp[n2] = True

        for i in range(n1, -1, -1):
            for j in range(n2, -1, -1):
                if i == n1 and j == n2:
                    continue # already True

                k = i + j
                take1 = False
                take2 = False

                # take from s1 -> uses dp[i+1][j] which is dp[j] (old value)
                if i < n1 and s1[i] == s3[k]:
                    take1 = dp[j]

                # take from s2 -> uses dp[i][j+1] which is dp[j+1] (already updated)
                if j < n2 and s2[j] == s3[k]:
                    take2 = dp[j + 1]

                dp[j] = take1 or take2
        
        return dp[0]