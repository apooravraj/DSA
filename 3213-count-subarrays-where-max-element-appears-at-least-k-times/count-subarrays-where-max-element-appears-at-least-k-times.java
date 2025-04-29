class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length;
        int maxm = 0;

        // Find the maximum element in the array
        for (int i : nums) maxm = Math.max(maxm, i);

        int l = 0;
        int count = 0;
        long ans = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == maxm) count++;

            while (count >= k) {
                // Add subarrays ending at r starting from l
                ans += (n - r); 
                if (nums[l] == maxm) count--;
                l++;
            }
        }

        return ans;
    }
}
