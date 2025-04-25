class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long interesting_subarrays = 0;
        int prefix_count = 0;

        unordered_map<int, long long> mod_freq;
        mod_freq[0] = 1;

        for (int pos = 0; pos < n; pos++) {
            if (nums[pos] % modulo == k)
                prefix_count++;

            prefix_count %= modulo;

            int target_mod = (prefix_count - k + modulo) % modulo;
            if (mod_freq.count(target_mod)) {
                interesting_subarrays += mod_freq[target_mod];
            }

            mod_freq[prefix_count]++;
        }

        return interesting_subarrays;
    }
};
