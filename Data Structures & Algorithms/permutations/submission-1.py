class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        path = []
        on_path = [False] * n

        def dfs(i):
            if i == n:
                ans.append(path.copy())
            
            for j in range(n):
                if not on_path[j]:
                    path.append(nums[j])
                    on_path[j] = True
                    dfs(i + 1)
                    path.pop()
                    on_path[j] = False
        
        dfs(0)
        return ans