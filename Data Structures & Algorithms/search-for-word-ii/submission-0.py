class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()

        # insert word into trie
        for word in words:
            node = root
            for ch in word:
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
            node.word = word

        rows, cols = len(board), len(board[0])
        ans = []

        def dfs(r, c, node):
            if r < 0 or r >= rows or c < 0 or c >= cols or board[r][c] not in node.children:
                return
            
            ch = board[r][c]
            next_node = node.children[ch]
            if next_node.word:
                ans.append(next_node.word)
                next_node.word = None # prevent duplicate
            
            # mark as visited
            board[r][c] = "#"

            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr, nc = r + dr, c + dc
                dfs(nr, nc, next_node)
            
            # recover the cell
            board[r][c] = ch
        
        for r in range(rows):
            for c in range(cols):
                dfs(r, c, root)
        
        return ans