class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        INF = 10 ** 9
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        dist = [[INF] * n for _ in range(n)]
        dist[0][0] = grid[0][0]

        pq = []
        heapq.heappush(pq, (grid[0][0], 0, 0))
        visit = set()

        while pq:
            level, r, c = heapq.heappop(pq)

            if (r, c) in visit:
                continue
            visit.add((r, c))

            if r == n - 1 and c == n - 1:
                return level

            for dr, dc in dirs:
                nr, nc = dr + r, dc + c
                if 0 <= nr < n and 0 <= nc < n:
                    new_level = max(level, grid[nr][nc])
                    if new_level < dist[nr][nc]:
                        dist[nr][nc] = new_level
                        heapq.heappush(pq, (new_level, nr, nc))