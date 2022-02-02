class Solution:
    def winnerOfGame(self, c: str) -> bool:
        a = b = 0
        for i in range(1,len(c)-1):
            if c[i-1] == c[i] == c[i+1]:
                if c[i] == 'A':
                    a += 1
                else:
                    b += 1         
        return a > b
