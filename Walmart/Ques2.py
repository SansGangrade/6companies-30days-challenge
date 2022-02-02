class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[(0, 0)] * n for _ in range(n)]
        
        for left in range(n - 1, -1, -1):
            for right in range(left, n):
                if left == right:  # Base case
                    dp[left][right] = (piles[left], 0)
                    continue
                    
                pickLeft = dp[left + 1][right]
                pickRight = dp[left][right - 1]
                if piles[left] + pickLeft[1] > piles[right] + pickRight[1]:  # If the left choice has higher score than the right choice
                    dp[left][right] = (piles[left] + pickLeft[1], pickLeft[0])  # then pick left
                else:
                    dp[left][right] = (piles[right] + pickRight[1], pickRight[0])  # else pick right

        aliceScore, leeScore = dp[0][n - 1]
        return aliceScore > leeScore
