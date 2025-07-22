class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> cumSum(n, 0);
        cumSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + nums[i];
        }

        vector<int> mp(10001, -1);
        int result = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            i = max(i, mp[nums[j]]+1);
            int jthSum = cumSum[j];
            int ithSum = i-1 < 0 ? 0 : cumSum[i-1];

            result = max(result, jthSum - ithSum);

            mp[nums[j]] = j;
            j++;
        }

        return result;
        
    }
};