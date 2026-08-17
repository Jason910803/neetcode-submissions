class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        
        graph = defaultdict(list)
        for word in wordList:
            for i in range(len(word)):
                pattern = word[:i] + "#" + word[i + 1:]
                graph[pattern].append(word)
        
        q = deque()
        q.append(beginWord)
        res = 1
        visit = set()

        while q:
            for _ in range(len(q)):
                word = q.popleft()

                if word == endWord:
                    return res

                for i in range(len(word)):
                    pattern = word[:i] + "#" + word[i + 1:]
                    for nei in graph[pattern]:
                        if nei in visit:
                            continue
                        
                        visit.add(nei)
                        q.append(nei)
                
            res += 1
        
        return 0
