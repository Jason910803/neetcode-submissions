class Solution:
    def minWindow(self, s: str, t: str) -> str:
        s_map = defaultdict(int)
        t_map = defaultdict(int)
        for ch in t:
            t_map[ch] += 1
        
        s_count = 0
        t_count = len(t_map)

        str_count = 10 ** 9
        str_start = 0

        l = 0
        for r in range(len(s)):
            if s[r] in t_map:
                s_map[s[r]] += 1
                
                if s_map[s[r]] == t_map[s[r]]:
                    s_count += 1
            
                while s_count == t_count:
                    if (r - l) + 1 < str_count:
                        str_count = r - l + 1
                        str_start = l
                    
                    if s[l] in s_map:
                        s_map[s[l]] -= 1
                        if s_map[s[l]] < t_map[s[l]]:
                            s_count -= 1

                    l += 1
        
        return s[str_start : str_start + str_count] if str_count != 10 ** 9 else ""