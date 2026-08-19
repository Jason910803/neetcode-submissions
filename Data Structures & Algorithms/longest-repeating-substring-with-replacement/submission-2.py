class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        return self.method_1(s, k)
    
    def method_1(self, s, k):
        # Time: O(26N), Space: O(1)
        char_map = defaultdict(int)
        left = 0
        max_len = 0

        for right in range(len(s)):
            char_map[s[right]] += 1

            while (right - left + 1) - max(char_map.values()) > k:
                char_map[s[left]] -= 1
                left += 1
            
            max_len = max(max_len, right - left + 1)
        
        return max_len