class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])
        pacific = set()
        atlantic = set()
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        def dfs(r, c, visit):
            if (r, c) in visit: return
            
            visit.add((r, c))
            for dr, dc in dirs:
                row, col = dr + r, dc + c
                if row in range(rows) and col in range(cols) and heights[row][col] >= heights[r][c]:
                    dfs(row, col, visit)
        
        for c in range(cols):
            dfs(0, c, pacific)
            dfs(rows - 1, c, atlantic)
            
        for r in range(rows):
            dfs(r, 0, pacific)
            dfs(r, cols - 1, atlantic)

        res = [[r, c] for r, c in pacific & atlantic]
        return res
