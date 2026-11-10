class Solution(object):
    def climbStairs(self, n, costs):
        dp1 = 0
        dp2 = 0
        dp3 = 0

        for i in range (1, n + 1):
            curr = costs[i-1] + min(
                dp3 + 1,
                dp2 + 4,
                dp1 + 9
            )

            dp1 = dp2
            dp2 = dp3
            dp3 = curr

        return dp3    
        