class Solution {
public:
    static int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), balance = 0;
        unordered_map<int, int> cntB;
        cntB.reserve(n);
        cntB[balance] = 1;
        int ans = 0, sum = 0;

        for(int x : nums) {
            if(x==target) sum+=cntB[balance++];
            else sum-=cntB[--balance];

            cntB[balance]++;
            ans+=sum;
        }
        return ans;
    }
};