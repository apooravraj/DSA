class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i,x in enumerate(nums):
            total = 0
            while x > 0:
                x, r = divmod(x, 10)
                total  = total + r
            if total == i: return i
        return -1
        