class Solution:
    #Function to find total number of unique paths.
    def NumberOfPaths(self,a, b):
        #code here
        dp = [[1] * b for _ in range(a)]
        for i in range(1, a):
            for j in range(1, b):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]            
        return dp[-1][-1]

#{ 
#  Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        a_b = [int(x) for x in input().strip().split()]
        a = a_b[0]
        b = a_b[1]
        ob = Solution()
        print(ob.NumberOfPaths(a, b))
