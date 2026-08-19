class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        max_len = 0
        window_chars = set()

        for right in range(len(s)):
            char = s[right]

            while char in window_chars:
                window_chars.remove(s[left])
                left += 1
            
            window_chars.add(char)
            max_len = max(max_len, right - left + 1)
        
        return max_len
