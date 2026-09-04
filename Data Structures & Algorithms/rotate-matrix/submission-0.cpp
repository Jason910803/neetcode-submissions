class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose then reverse
        int m = matrix.size();
        int n = matrix[0].size();

        // transpose
        for (int r = 0; r < m; r++) {
            for (int c = r + 1; c < n; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        // reverse
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};