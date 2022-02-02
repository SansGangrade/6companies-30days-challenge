class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        effs = sorted([(efficiency[i], i) for i in range(n)], key=lambda e: -e[0])
        
        h = []
        maxPerf = -inf
        totalSpeed = 0
        for eff, i in effs:
            if len(h) < k:
                heappush(h, speed[i])
                totalSpeed += speed[i]
            elif speed[i] > h[0]:
                totalSpeed -= heappop(h)  
                heappush(h, speed[i])  
                totalSpeed += speed[i]
                
            maxPerf = max(maxPerf, totalSpeed*eff)
            
        return maxPerf%(pow(10, 9) + 7)
© 2022 GitHub, Inc.
Terms
Privacy
