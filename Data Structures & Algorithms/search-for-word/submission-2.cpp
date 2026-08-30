class Solution {
public:
    bool backtrack(
        vector<vector<char>>& board,
        const string& word,
        int r,
        int c,
        int index
    ) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        char tmp = board[r][c];
        board[r][c] = '#';

        bool exist = backtrack(board, word, r + 1, c, index + 1) ||
                     backtrack(board, word, r - 1, c, index + 1) ||
                     backtrack(board, word, r, c + 1, index + 1) ||
                     backtrack(board, word, r, c - 1, index + 1);
        
        board[r][c] = tmp;

        return exist;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
