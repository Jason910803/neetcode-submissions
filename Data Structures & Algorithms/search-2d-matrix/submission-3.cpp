class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int up = 0;
        int down = m;

        while (up < down) {
            int mid = up + (down - up) / 2;

            if (matrix[mid][n - 1] >= target) {
                down = mid;
            } else {
                up = mid + 1;
            }
        }

        if (up == m) return false;

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target == matrix[up][mid]) {
                return true;
            } else if (target > matrix[up][mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};
