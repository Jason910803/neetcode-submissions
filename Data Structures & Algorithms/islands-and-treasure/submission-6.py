class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows = len(grid)
        cols = len(grid[0])
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        # multi-source bfs
        q = deque()

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append((r, c))
        
        while q:
            r, c = q.popleft()

            for dr, dc in dirs:
                nr, nc = dr + r, dc + c
                if nr in range(rows) and nc in range(cols) and grid[nr][nc] == 2 ** 31 - 1:
                    q.append((nr, nc))
                    grid[nr][nc] = grid[r][c] + 1

