class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        vector<int> ans;
        while (top <= bottom && left <= right) {
            // from left to right
            for (int c = left; c <= right; c++) {
                ans.push_back(matrix[top][c]);
            }
            top++;

            // from top to bottom
            for (int r = top; r <= bottom; r++) {
                ans.push_back(matrix[r][right]);
            }
            right--;

            // from right to left
            if (top <= bottom) {
                for (int c = right; c >= left; c--) {
                    ans.push_back(matrix[bottom][c]);
                }
            }
            bottom--;

            // from bottom to top
            if (left <= right) {
                for (int r = bottom; r >= top; r--) {
                    ans.push_back(matrix[r][left]);
                }
            }
            left++;
        }

        return ans;
    }
};