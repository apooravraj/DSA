class Solution {
public:
    int findMin(vector<int>& nums) {
        const int n=nums.size();
        if (n==1) return nums[0];
        if (n==2) return (nums[0]<nums[1])?nums[0]:nums[1];
        int l=0, r=n-1, m, ans=0;
        while(l<=r){
            m=(r+l)/2;
            const int M=nums[m];
            
            // Track the index of the minimum value found
            if (nums[m]<nums[ans]) ans=m;
            if (nums[r]<nums[ans]) ans=r; 

            if (nums[r]<M) l=m+1;
            else if (nums[r]>M) r=m-1; 
            else r--;  //nums[r]==M 
        }
        return nums[ans];
    }
};