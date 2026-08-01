int player[20][20];
class Solution {
public:
    int game(int l, int r,  vector<int>& nums){
        if (l==r) return nums[l];
        if (player[l][r]!=INT_MIN) return player[l][r];
        return player[l][r]
            =max(nums[l]-game(l+1, r, nums), nums[r]-game(l, r-1, nums));
        
    }
    bool predictTheWinner(vector<int>& nums) {
        const int n=nums.size();
        for(int i=0; i<n; i++)
            fill_n(player[i], n, INT_MIN);
        return game(0, n-1, nums)>=0;
    }
};