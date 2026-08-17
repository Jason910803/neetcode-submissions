class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(word)
        rows, cols = len(board), len(board[0])
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        on_path = [[False] * cols for _ in range(rows)]

        def dfs(r, c, i) -> bool:
            if i == n:
                return True

            if r < 0 or r >= rows or c < 0 or c >= cols or on_path[r][c] or board[r][c] != word[i]:
                return False

            on_path[r][c] = True
            for dr, dc in dirs:
                nr, nc = dr + r, dc + c
                if dfs(nr, nc, i + 1):
                    return True
            on_path[r][c] = False

            return False

        
        for r in range(rows):
            for c in range(cols):
                if dfs(r, c, 0):
                    return True
        
        return False
