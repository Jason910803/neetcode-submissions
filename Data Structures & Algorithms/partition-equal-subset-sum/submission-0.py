class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        total = sum(nums)
        if total % 2 == 1:
            return False
        
        target = total // 2
        memo = {}

        def dfs(i, cur_sum) -> bool:
            if i == n or cur_sum > target:
                return False
            
            if cur_sum == target:
                return True

            if (i, cur_sum) in memo:
                return memo[(i, cur_sum)]
            
            take = dfs(i + 1, cur_sum + nums[i])
            skip = dfs(i + 1, cur_sum)

            res = take or skip
            memo[(i, cur_sum)] = res

            return res
        
        return dfs(0, 0)