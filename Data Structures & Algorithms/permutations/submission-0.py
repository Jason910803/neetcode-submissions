class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        path = []

        def dfs(i, s):
            if i == n:
                ans.append(path.copy())
            
            for num in s:
                path.append(num)
                dfs(i + 1, s - {num})
                path.pop()
        
        dfs(0, set(nums))
        return ans