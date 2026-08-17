class Solution:
    def countBits(self, n: int) -> List[int]:
        
        def helper(num):
            res = 0
            for i in range(11):
                if num & (1 << i):
                    res += 1
            return res
        
        res = []
        for i in range(n + 1):
            res.append(helper(i))
        
        return res