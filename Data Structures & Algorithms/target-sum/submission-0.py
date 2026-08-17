class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        memo = {}

        def dfs(i, cur_sum):
            if i == n:
                if cur_sum == target:
                    return 1
                else:
                    return 0
            
            if (i, cur_sum) in memo:
                return memo[(i, cur_sum)]
            
            # choose plus sign
            res = dfs(i + 1, cur_sum + nums[i])

            # choose minus sign
            res += dfs(i + 1, cur_sum - nums[i])

            memo[(i, cur_sum)] = res
            return res
        
        return dfs(0, 0)