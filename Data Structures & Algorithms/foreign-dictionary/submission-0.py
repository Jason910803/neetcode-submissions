class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        graph = defaultdict(list)
        indegree = {}

        nodes = set()
        for word in words:
            for ch in word:
                nodes.add(ch)
        
        for ch in nodes:
            indegree[ch] = 0
        
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]

            # case 1
            if len(w1) > len(w2) and w1.startswith(w2):
                return ""
            
            # case 2
            for a, b in zip(w1, w2):
                if a != b:
                    graph[a].append(b)
                    indegree[b] += 1
                    break
        
        q = deque([ch for ch in nodes if indegree[ch] == 0])
        topo = ""

        while q:
            ch = q.popleft()
            topo += ch

            for nei in graph[ch]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)
        
        return topo if len(topo) == len(nodes) else ""

