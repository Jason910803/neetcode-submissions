class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        indegree = [0] * numCourses

        for u, v in prerequisites:
            graph[v].append(u)
            indegree[u] += 1
        
        # queue all nodes with indegree = 0
        q = deque([i for i in range(numCourses) if indegree[i] == 0])

        topo = []

        while q:
            node = q.popleft()
            topo.append(node)

            for nei in graph[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)
        
        # need to check if has cycle
        if len(topo) != numCourses:
            return []

        return topo