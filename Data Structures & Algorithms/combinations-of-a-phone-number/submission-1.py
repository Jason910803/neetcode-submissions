class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        numbers = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

        if len(digits) == 0:
            return []
            
        n = len(digits)
        ans = []
        path = [""] * n

        def dfs(i):
            if i == n:
                ans.append("".join(path))
                return

            for ch in numbers[int(digits[i])]:
                path[i] = ch
                dfs(i + 1)
        
        dfs(0)
        return ans