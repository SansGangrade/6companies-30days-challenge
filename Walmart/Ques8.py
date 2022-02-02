#User function Template for python3

class Solution:
    def height(self, N):
        # code here
        if N <= 2:
            return 1
        D = (1 + 4*2*N)**.5
        root = (-1 + D)//2
        return int(root)

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        
        ob = Solution()
        print(ob.height(N))
# } Driver Code Ends
