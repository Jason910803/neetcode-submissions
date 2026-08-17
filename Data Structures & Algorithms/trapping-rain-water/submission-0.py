class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        prefix, suffix = [0] * n, [0] * n
        res = 0

        # use monotonic stack
        st = []

        # first build the prefix array
        for i in range(n):
            while st and st[-1] < height[i]:
                st.pop()
            
            if not st:
                prefix[i] = height[i]
            else:
                prefix[i] = st[0]
            
            st.append(height[i])
        
        st.clear()

        # then buld the suffix array
        for i in range(n - 1, -1, -1):
            while st and st[-1] < height[i]:
                st.pop()
            
            if not st:
                suffix[i] = height[i]
            else:
                suffix[i] = st[0]

            st.append(height[i])

        for i in range(n):
            res += min(prefix[i], suffix[i]) - height[i]
        
        return res


