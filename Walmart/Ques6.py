class Solution:
    #Complete this function
    def power(self,N,R):
        #Your code here
        MOD = 10**9 + 7
        if R == 0:
            return 1
        temp = self.power(N, R//2)
        if R % 2 == 0:
            return (temp*temp) % MOD
        else:
            return (N*temp*temp) % MOD

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math

def main():
    
    T=int(input())
    
    while(T>0):
        
        N=input()
        R=N[::-1]
        
        ob=Solution();
        ans=ob.power(int(N),int(R))
        print(ans)
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends
