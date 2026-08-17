class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows = len(grid)
        cols = len(grid[0])
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        def bfs(r, c):
            q = deque([(r, c)])
            visit = [[False] * cols for _ in range(rows)]
            visit[r][c] = True
            step = 0

            while q:
                for _ in range(len(q)):
                    row, col = q.popleft()

                    if grid[row][col] == 0:
                        return step

                    for dr, dc in dirs:
                        nr, nc = dr + row, dc + col
                        
                        if nr in range(rows) and nc in range(cols) and not visit[nr][nc] and grid[nr][nc] != -1:
                            q.append((nr, nc))
                            visit[nr][nc] = True
                
                step += 1
            
            return 2 ** 31 - 1
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2 ** 31 - 1:
                    grid[r][c] = bfs(r, c)
