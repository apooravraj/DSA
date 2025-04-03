import java.util.Arrays;

class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        if (n < 3) return 0; // At least three elements needed

        long res = 0;

        // Prefix maximum: prefixMax[i] = max(nums[0..i])
        int[] prefixMax = new int[n];
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = Math.max(prefixMax[i - 1], nums[i]);
        }

        // Suffix maximum: suffixMax[i] = max(nums[i..n-1])
        int[] suffixMax = new int[n];
        suffixMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = Math.max(suffixMax[i + 1], nums[i]);
        }

        // Iterate through the middle element j
        for (int j = 1; j < n - 1; j++) {
            long current = (long) (prefixMax[j - 1] - nums[j]) * suffixMax[j + 1];
            res = Math.max(res, current);
        }

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 10, 3, 5, 2};
        System.out.println(sol.maximumTripletValue(nums)); // Output: 35
    }
}