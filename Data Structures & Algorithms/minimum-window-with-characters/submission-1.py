class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l = 0
        t_dict = defaultdict(int)
        s_dict = defaultdict(int)
        for char in t:
            t_dict[char] += 1

        have, need = 0, len(t_dict)
        res_len, res = float("inf"), [-1, -1]

        for r in range(len(s)):
            s_dict[s[r]] += 1

            if s[r] in t_dict and s_dict[s[r]] == t_dict[s[r]]:
                have += 1
            
            while have == need:
                if (r - l + 1) < res_len:
                    res_len = r - l + 1
                    res = [l, r]

                s_dict[s[l]] -= 1
                if s[l] in t_dict and s_dict[s[l]] < t_dict[s[l]]:
                    have -= 1
                
                l += 1
            
        l, r = res
        return s[l:r + 1] if res_len != float("inf") else ""
