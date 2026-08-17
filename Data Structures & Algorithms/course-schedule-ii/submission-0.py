class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        ans = []

        graph = { i: [] for i in range(numCourses) }
        for a, b in prerequisites:
            graph[a].append(b)

        UNVISITED = 0
        VISITING = 1
        VISITED = 2
        status = [UNVISITED] * numCourses

        def dfs(i):
            if status[i] == VISITING:
                # has cycle
                return False
            
            if status[i] == VISITED:
                return True
            
            status[i] = VISITING
            for nei in graph[i]:
                if not dfs(nei):
                    # if return False, then directly return False
                    return False
            
            status[i] = VISITED
            # the most important step is to add this course to ans list
            ans.append(i)
            return True
        
        for i in range(numCourses):
            if not dfs(i):
                return []
        
        return ans
