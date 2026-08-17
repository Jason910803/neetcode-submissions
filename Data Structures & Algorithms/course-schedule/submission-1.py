class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = {i: [] for i in range(numCourses)}
        for n1, n2 in prerequisites:
            adj[n1].append(n2)
        
        UNVISITED = 0
        VISITING = 1
        VISITED = 2

        states = [UNVISITED] * numCourses

        def dfs(i):
            if states[i] == VISITING:
                return False
            
            if states[i] == VISITED:
                return True
            
            states[i] = VISITING
            
            for j in adj[i]:
                if not dfs(j):
                    return False
            
            states[i] = VISITED
            return True
        
        for i in range(numCourses):
            if states[i] == UNVISITED:
                if not dfs(i):
                    return False
        
        return True