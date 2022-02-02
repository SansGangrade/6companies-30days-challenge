class Solution:
    def getMoneyAmount(self, n: int) -> int:
        dp = [[0] * (n + 2) for _ in range(n + 2)]
        for l in range(n, 0, -1):
            for r in range(l + 1, n + 1):
                dp[l][r] = math.inf
                for pick in range(l, r + 1):
                    leftCost = dp[l][pick - 1] + pick  
                    rightCost = dp[pick + 1][r] + pick
                    cost = max(leftCost, rightCost)
                    dp[l][r] = min(dp[l][r], cost)

        return dp[1][n]
