class DSU {
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;
        if (sz[px] > sz[py]) swap(px, py);
        parent[px] = py;
        sz[py] += sz[px];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1);

        for (const auto& edge : edges) {
            if (!dsu.unite(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};