class Solution:
    def kthLargestNumber(self, n: List[str], k: int) -> str:
        a = sorted(n, key = lambda x : int(x))
        return a[-k]
