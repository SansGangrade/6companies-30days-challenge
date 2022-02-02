class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = defaultdict(dict)
        for i, (a, b) in enumerate(edges):
            graph[a][b] = succProb[i]
            graph[b][a] = succProb[i]
        
        pq = [(-1, start)]
        seen = {start:1}
        
        while pq:
            prob, node = heapq.heappop(pq)
            if node == end:
                return -prob
            for nxt in graph[node]:
                newProb = -prob*graph[node][nxt]
                if nxt not in seen or seen[nxt] < newProb:
                    seen[nxt] = newProb
                    heapq.heappush(pq, (-newProb, nxt))
        return 0
