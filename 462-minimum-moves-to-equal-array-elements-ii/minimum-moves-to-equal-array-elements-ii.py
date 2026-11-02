class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        change = nums[len(nums) // 2]

        total = 0
        for num in nums:
            total = total + abs(change - num)

        return total