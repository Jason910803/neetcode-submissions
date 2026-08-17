class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        total = 0
        res = 0

        g = defaultdict(int)
        g[0] = 1

        for num in nums:
            total += num
            diff = total - k
            
            if diff in g:
                res += g[diff]
            
            g[total] += 1
        
        return res