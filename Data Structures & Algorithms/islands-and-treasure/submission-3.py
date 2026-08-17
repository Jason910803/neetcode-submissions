class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows = len(grid)
        cols = len(grid[0])
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        visit = [[False] * cols for _ in range(rows)]

        # multi-source bfs
        q = deque()

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append((r, c))
                    visit[r][c] = True
        
        step = 0
        while q:
            for _ in range(len(q)):
                r, c = q.popleft()
                grid[r][c] = step

                for dr, dc in dirs:
                    nr, nc = dr + r, dc + c
                    if nr in range(rows) and nc in range(cols) and not visit[nr][nc] and grid[nr][nc] == 2 ** 31 - 1:
                        q.append((nr, nc))
                        visit[nr][nc] = True
            
            step += 1