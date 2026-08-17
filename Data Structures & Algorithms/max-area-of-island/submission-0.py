class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        visit = set()
        ans = 0

        def dfs(i, j):
            if i not in range(rows) or j not in range(cols):
                return 0
            
            if grid[i][j] == 0:
                return 0
            
            if (i, j) in visit:
                return 0

            visit.add((i, j))
            return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1)
        
        for row in range(rows):
            for col in range(cols):
                count = dfs(row, col)
                ans = max(ans, count)
        
        return ans