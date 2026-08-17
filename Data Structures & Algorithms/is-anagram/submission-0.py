class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_count = defaultdict(int)

        for char in s:
            s_count[char] += 1
        
        for char in t:
            s_count[char] -= 1

        for value in s_count.values():
            if value != 0:
                return False
        
        return True