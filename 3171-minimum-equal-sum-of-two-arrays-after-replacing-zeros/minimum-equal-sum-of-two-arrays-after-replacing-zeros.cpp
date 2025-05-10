class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;

        for (int &num : nums1) {
            sum1 += num == 0 ? 1 : num;
            zero1 += num == 0 ? 1 : 0;
        }

        for (int &num : nums2) {
            sum2 += num == 0 ? 1 : num;  
            zero2 += num == 0 ? 1 : 0;
        }

        if ((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0)) {
            return -1;
        }

        return max(sum1, sum2);
    }
};
