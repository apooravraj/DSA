class Solution {
public:
// APOORAV RAJ
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMaxi(n);
        vector<int> rightMaxk(n);

        for(int j = 1; j < n; j++) {
            leftMaxi[j] = max(leftMaxi[j-1], nums[j-1]);
        }
        
        for(int j = n-2; j >= 0; j--) {
            rightMaxk[j] = max(rightMaxk[j+1], nums[j+1]);
        }

        long long result = 0;
        for(int j = 1; j < n; j++) {
           result = max(result, (long long)(leftMaxi[j] - nums[j]) * rightMaxk[j]);
        }
        return result;
        
        }
};