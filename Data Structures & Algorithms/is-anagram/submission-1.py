class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        left, right = {}, {}
        for i in range(len(s)):
            left[s[i]] = left.get(s[i], 0) + 1
            right[t[i]] = right.get(t[i], 0) + 1
        
        return left == right
