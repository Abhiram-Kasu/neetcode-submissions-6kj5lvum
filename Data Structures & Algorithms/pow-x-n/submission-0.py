class Solution:

    def myPow(self, x: float, n: int) -> float:
        def recur(curr, p):
            if p == 0: 
                return 1
            if p % 2 == 0: 
                res = recur(curr, p/2)
                return res * res;
            else: 
                return curr * recur(curr, p-1)
        res = recur(x, abs(n))
        return 1/res if n < 0 else res