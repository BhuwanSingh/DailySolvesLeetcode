class Solution:
    def findXSum(self, a: List[int], k: int, x: int) -> List[int]:
        return [sum(map(prod,nlargest(x,Counter(a[i:i+k]).items(),itemgetter(1,0)))) for i in range(len(a)-k+1)]