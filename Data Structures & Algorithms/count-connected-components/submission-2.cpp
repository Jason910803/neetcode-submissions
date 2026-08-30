class Solution {
private:
    void dfs(
        const vector<vector<int>>& graph,
        vector<bool>& visited,
        int node
    ) {
        visited[node] = true;

        for (int nei : graph[node]) {
            if (!visited[nei]) {
                dfs(graph, visited, nei);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                result++;
                dfs(graph, visited, i);
            }
        }

        return result;
    }
};
