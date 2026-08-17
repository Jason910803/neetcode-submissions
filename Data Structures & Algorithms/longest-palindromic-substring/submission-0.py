class Solution:
    def longestPalindrome(self, s: str) -> str:
        res, resLen = 0, 1

        for i in range(len(s)):
            # for odd
            l, r = i - 1, i + 1
            while l >= 0 and r < len(s):
                if s[l] == s[r]:
                    if r - l + 1 > resLen:
                        resLen = r - l + 1
                        res = l
                    l -= 1
                    r += 1
                else:
                    break
            
            # for even
            if i + 1 < len(s) and s[i + 1] == s[i]:
                if 2 > resLen:
                    resLen = 2
                    res = i
                l, r = i - 1, i + 2
                while l >= 0 and r < len(s):
                    if s[l] == s[r]:
                        if r - l + 1 > resLen:
                            resLen = r - l + 1
                            res = l
                        l -= 1
                        r += 1
                    else:
                        break
        
        return s[res : res + resLen]