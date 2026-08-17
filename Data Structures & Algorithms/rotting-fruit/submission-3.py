class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # I think this is a typical problem to use the multi-source bfs technique
        rows, cols = len(grid), len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        q = deque()
        fresh = False
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    q.append((r, c))
                if grid[r][c] == 1:
                    fresh = True
        
        if not fresh:
            return 0
        elif not q:
            return -1

        step = -1
        while q:
            for _ in range(len(q)):
                r, c = q.popleft()
                for dr, dc in dirs:
                    nr, nc = dr + r, dc + c
                    if nr in range(rows) and nc in range(cols) and grid[nr][nc] == 1:
                        q.append((nr, nc))
                        grid[nr][nc] = 2
            
            step += 1

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    return -1
        
        return step
