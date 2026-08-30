class Solution {
private:
    bool dfs(
        const vector<vector<int>>& graph,
        vector<bool>& visited,
        int start,
        int parent
    ) {
        visited[start] = true;

        for (int nei : graph[start]) {
            if (!visited[nei]) {
                if (dfs(graph, visited, nei, start)) {
                    return true;
                }
            } else if (nei != parent) {
                return true;
            }
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        
        vector<bool> visited(n, 0);
        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool hasCycle = dfs(graph, visited, 0, -1);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return !hasCycle;
    }
};
