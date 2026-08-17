class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        for a, b in tickets:
            # using heap to store the path
            heapq.heappush(graph[a], b)
        
        res = []

        def dfs(i):
            while graph[i]:
                dst = heapq.heappop(graph[i])
                dfs(dst)
            res.append(i)

        dfs("JFK")
        return res[::-1]