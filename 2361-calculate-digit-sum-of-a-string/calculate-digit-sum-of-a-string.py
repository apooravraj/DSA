class Solution:
    def digitSum(self, s: str, k: int) -> str:
        
        while len(s)>k:
            t = []
            for i in range(0,len(s),k):
                group = s[i:i+k]
                summ = sum(int(digit) for digit in group)
                t.append(str(summ))
            s = "".join(t)
        return s