using int2=array<int, 2>;
const int N=101;
int2 pos[N];
class Solution {
public:
    static int minimumDistance(vector<int>& nums) {
        const int n=nums.size(), M=*max_element(nums.begin(), nums.end());
        const int2 none={-1, -1};
        fill_n(pos, M+1, none);
        int ans=INT_MAX;
        for(int k=0; k<n; k++){
            const int x=nums[k];
            if (pos[x][1]!=-1){
                ans=min(ans, (k-pos[x][1])<<1);
            }
            pos[x][1]=exchange(pos[x][0], k);
        }
        return ans==INT_MAX?-1:ans;
    }
};