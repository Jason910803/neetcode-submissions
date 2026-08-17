class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = [[] for _ in range(n + 1)]
        for u, v, t in times:
            graph[u].append((v, t))
        
        # dijkstra algo.
        INF = 10 ** 18
        dist = [INF] * (n + 1)
        dist[k] = 0

        pq = [(0, k)] # priority queue (distance, node)

        while pq:
            cur_dist, u = heapq.heappop(pq)

            # lazy deletion
            if cur_dist > dist[u]:
                continue
            
            # relaxation
            for v, w in graph[u]:
                new_dist = cur_dist + w
                if new_dist < dist[v]:
                    dist[v] = new_dist
                    heapq.heappush(pq, (new_dist, v))
        
        ans = max(dist[1:])
        
        return ans if ans < INF else -1