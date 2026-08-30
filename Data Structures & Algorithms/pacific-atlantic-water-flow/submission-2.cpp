class Solution {
private:
    void multiSourceBFS(
        queue<pair<int, int>>& q, 
        const vector<vector<int>>& heights,
        vector<vector<char>>& state,
        char mask
    ) {
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int currHeight = heights[r][c];

            for (auto& [dr, dc] : directions) {
                int nr = dr + r;
                int nc = dc + c;

                if (nr < 0 || nr >= heights.size() || nc < 0 || nc >= heights[0].size() || heights[nr][nc] < currHeight) {
                    continue;
                }

                if ((state[nr][nc] & mask) == mask) {
                    continue;
                }

                q.push({nr, nc});
                state[nr][nc] |= mask;
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<char>> state(m, vector<char>(n, 0));
        queue<pair<int, int>> pacific, atlantic;

        for (int i = 0; i < m; i++) {
            pacific.push({i, 0});
            state[i][0] |= 1;
            atlantic.push({i, n - 1});
            state[i][n - 1] |= 2; 
        }

        for (int i = 0; i < n; i++) {
            if ((state[0][i] & 1) == 0) {
                pacific.push({0, i});
                state[0][i] |= 1;
            }
            if ((state[m - 1][i] & 2) == 0) {
                atlantic.push({m - 1, i});
                state[m - 1][i] |= 2;
            }
        }

        multiSourceBFS(pacific, heights, state, 1);
        multiSourceBFS(atlantic, heights, state, 2);

        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (state[i][j] == 3) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
