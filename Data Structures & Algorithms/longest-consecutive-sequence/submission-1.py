class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
            
        s = set(nums)
        res = 1

        for num in s:
            if num - 1 in s:
                continue
            
            count = 1
            while num + 1 in s:
                num += 1
                count += 1
            
            res = max(count, res)
        
        return res