class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        visit = set()
        q = deque()
        res = 0

        def bfs(r, c):
            q.append((r, c))
            visit.add((r, c))

            while q:
                r, c = q.popleft()
                dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

                for dx, dy in dir:
                    row = dx + r
                    col = dy + c

                    if row in range(rows) and col in range(cols) and grid[row][col] == "1" and (row, col) not in visit:
                        q.append((row, col))
                        visit.add((row, col))

        
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "1" and (row, col) not in visit:
                    bfs(row, col)
                    res += 1
        
        return res