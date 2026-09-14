class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < k + 1; i++) {
            vector<int> temp = dist;

            for (const auto& edge : flights) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (temp[u] == INT_MAX) continue;
                if (temp[u] + w < dist[v]) {
                    dist[v] = temp[u] + w;
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
