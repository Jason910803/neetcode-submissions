class Solution:
    def solve(self, board: List[List[str]]) -> None:
        rows, cols = len(board), len(board[0])
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def dfs(r, c):
            if r not in range(rows) or c not in range(cols):
                return
            
            if board[r][c] != "O":
                return

            board[r][c] = "U"
            for dr, dc in dirs:
                nr, nc = dr + r, dc + c
                dfs(nr, nc)
        
        for r in range(rows):
            dfs(r, 0)
            dfs(r, cols - 1)
        
        for c in range(cols):
            dfs(0, c)
            dfs(rows - 1, c)
        
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = "X"

                if board[r][c] == "U":
                    board[r][c] = "O"
