class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inorder(numCourses);
        vector<int> topo;

        for (auto& pre : prerequisites) {
            int to = pre[0];
            int from = pre[1];
            graph[from].push_back(to);
            inorder[to]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inorder[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);

            for (int nei : graph[curr]) {
                inorder[nei]--;
                if (inorder[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return topo.size() == numCourses;
    }
};
