class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        vanisha=nums[len(nums)//2]
        return sum(abs(vanisha-num) for num in nums)