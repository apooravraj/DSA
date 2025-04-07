class Solution {
    public boolean canPartition(int[] nums) {
        if (nums == null || nums.length == 0) return false;

        int sum = 0;
        for (int i : nums) sum += i;

        if (sum % 2 == 1) return false;
        sum /= 2;

        boolean[] dp = new boolean[sum + 1];
        dp[0] = true;

        for (int num : nums) {
            for (int j = sum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[sum];
    }
}
