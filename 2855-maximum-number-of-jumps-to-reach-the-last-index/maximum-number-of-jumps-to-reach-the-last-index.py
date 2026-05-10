class Solution:
    def maximumJumps(self, nums, target):

        n = len(nums)

        # dp[i] stores maximum jumps to reach index i
        dp = [-1] * n

        # Starting index needs 0 jumps
        dp[0] = 0

        for i in range(1, n):

            # Check all previous indices
            for j in range(i):

                # Valid jump and previous index reachable
                if abs(nums[i] - nums[j]) <= target and dp[j] != -1:

                    # Update maximum jumps
                    dp[i] = max(dp[i], dp[j] + 1)

        return dp[-1]