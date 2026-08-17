class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = {node: [] for node in range(n + 1)}
        ans = -1

        for u, v, t in times:
            graph[u].append((v, t))
        
        # dijkstra algo.
        dist = {node: float('inf') for node in range(n + 1)}
        dist[k] = 0
        pq = [(0, k)] # priority queue (distance, node)

        while pq:
            cur_dist, u = heapq.heappop(pq)

            # lazy deletion
            if cur_dist > dist[u]:
                continue
            
            # relaxation
            for v, w in graph[u]:
                if cur_dist + w < dist[v]:
                    dist[v] = cur_dist + w
                    heapq.heappush(pq, (dist[v], v))
        

        for i in range(1, n + 1):
            if dist[i] > ans:
                ans = dist[i]
        
        return ans if ans != float('inf') else -1