class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        g = defaultdict(list)
        for course, pre in prerequisites:
            g[course].append(pre)

        UNVISITED = 0
        VISITING = 1
        VISITED = 2
        status = [UNVISITED] * numCourses

        def dfs(node) -> bool:
            state = status[node]
            if state == VISITING:
                return False
            elif state == VISITED:
                return True
            
            status[node] = VISITING
            for ner in g[node]:
                if not dfs(ner):
                    return False
            status[node] = VISITED
            return True
        
        for course in range(numCourses):
            if not dfs(course):
                return False
        
        return True