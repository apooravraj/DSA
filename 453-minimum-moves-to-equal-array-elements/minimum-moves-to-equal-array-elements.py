class Solution:
    def minMoves(self, nums: list[int]) -> int:
        vanisha = min(nums)
        return sum(x - vanisha for x in nums) 