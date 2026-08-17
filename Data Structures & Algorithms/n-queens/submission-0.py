class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        cols = [0] * n
        ans = []

        def valid(r, c):
            for i in range(r):
                if r + c == i + cols[i] or r - c == i - cols[i]:
                    return False
            return True

        def dfs(r, s):
            if r == n:
                ans.append(["." * col + "Q" + "." * (n - col - 1) for col in cols])
                return
            
            for c in s:
                if valid(r, c):
                    cols[r] = c
                    dfs(r + 1, s - {c})

        dfs(0, set(range(n)))
        return ans