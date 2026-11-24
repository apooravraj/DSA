class Solution:
    def maxLength(self, nums: List[int]) -> int:
        M = (0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5)
        mask = l = best = 0
        for r, x in enumerate(nums):
            m = M[x]
            while mask & m:
                mask ^= M[nums[l]]
                l += 1
            mask |= m
            if r - l + 1 > best:
                best = r - l + 1
        return best if best > 2 else 2