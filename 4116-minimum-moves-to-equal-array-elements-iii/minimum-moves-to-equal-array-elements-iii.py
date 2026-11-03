class Solution:
    def minMoves(self, nums: List[int]) -> int:
        mx = max(nums)
        total = 0
        for x in nums:
            total = total + mx - x
        return total    