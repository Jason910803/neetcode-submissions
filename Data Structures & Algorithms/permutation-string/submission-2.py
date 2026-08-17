class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        s1_map = [0] * 26
        s2_map = [0] * 26

        for ch in s1:
            s1_map[ord(ch) - ord("a")] += 1
        
        # fist build the s2_map
        for i in range(len(s1)):
            s2_map[ord(s2[i]) - ord("a")] += 1

        if s1_map == s2_map:
            return True

        l = 0
        for r in range(len(s1), len(s2)):
            s2_map[ord(s2[l]) - ord("a")] -= 1
            s2_map[ord(s2[r]) - ord("a")] += 1
            l += 1

            if s1_map == s2_map:
                return True
        
        return False