class Solution {
public:
    static int countValidSelections(vector<int>& nums) {
        const int n=nums.size();
        vector<int> zIdx;
        if (nums[0]==0) zIdx.push_back(0);
        for(int i=1; i<n; i++){
            if(nums[i]==0) zIdx.push_back(i);
            nums[i]+=nums[i-1];
        }
        int cnt=0, sum=nums[n-1];
        for (int z: zIdx){
            if (2*nums[z]==sum) cnt+=2;
            if (abs(2*nums[z]-sum)==1) cnt++;
        }
        return cnt;
    }
};