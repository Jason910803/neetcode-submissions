class Solution {
private:
    struct Node {
        Node* children[26]{};
        string word;
    };

    vector<string> ans;
    Node* root;

    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
        if (
            r < 0 || 
            r >= board.size() || 
            c < 0 || 
            c >= board[0].size() || 
            board[r][c] == '#'
        ) {
            return;
        }

        char ch = board[r][c];
        Node* next = node->children[ch - 'a'];
        if (!next) return;

        if (!next->word.empty()) {
            ans.push_back(next->word);
            next->word.clear();
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, next);
        dfs(board, r - 1, c, next);
        dfs(board, r, c + 1, next);
        dfs(board, r, c - 1, next);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        // build trie
        root = new Node();
        for (string word : words) {
            Node* cur = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!cur->children[idx]) {
                    cur->children[idx] = new Node();
                }
                cur = cur->children[idx];
            }
            cur->word = word;
        }

        // traverse the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};
