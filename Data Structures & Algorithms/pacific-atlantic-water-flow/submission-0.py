class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])
        pacific = set()
        atlantic = set()

        def dfs(r, c, isPacific):
            if isPacific:
                if (r, c) in pacific: return
            else:
                if (r, c) in atlantic: return
            
            dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
            if isPacific:
                pacific.add((r, c))
                for dr, dc in dirs:
                    row, col = dr + r, dc + c
                    if row in range(rows) and col in range(cols) and heights[row][col] >= heights[r][c]:
                        dfs(row, col, isPacific)
            else:
                atlantic.add((r, c))
                for dr, dc in dirs:
                    row, col = dr + r, dc + c
                    if row in range(rows) and col in range(cols) and heights[row][col] >= heights[r][c]:
                        dfs(row, col, isPacific)
        
        for c in range(cols):
            # pacific
            if heights[0][c] not in pacific:
                dfs(0, c, True)
            
            # atlantic
            if heights[rows - 1][c] not in atlantic:
                dfs(rows - 1, c, False)
            
        for r in range(rows):
            # pacific
            if heights[r][0] not in pacific:
                dfs(r, 0, True)
            
            # atlantic
            if heights[r][cols - 1] not in atlantic:
                dfs(r, cols - 1, False)

        res = [[r, c] for r, c in pacific & atlantic]
        return res
