class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // graph: vector<vector<pair<int, int>>
        // heap: priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>
        // dist: vector<int>

        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            graph[u].push_back({v, t});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        dist[k] = 0;
        q.push({0, k});

        while (!q.empty()) {
            auto [d, node] = q.top();
            q.pop();

            if (d > dist[node]) continue;

            for (const auto& [v, t] : graph[node]) {
                int cur_dist = d + t;
                if (cur_dist < dist[v]) {
                    dist[v] = cur_dist;
                    q.push({cur_dist, v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n + 1; i++) {
            ans = max(ans, dist[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
