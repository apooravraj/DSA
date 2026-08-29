using int2=pair<int, int>;
constexpr int N=1e5;
int2 nIdx[N];
int seq[N], values[N];
class Solution {
public:
    static vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int n=nums.size();
        for(int i=0; i<n; i++)
            nIdx[i]={nums[i], i};
        
        // Sort nIdx
        sort(nIdx, nIdx+n);

        vector<int2> group={{0, 0}};// [s, e]= interval for group 
        group.reserve(n);
        int prev=nIdx[0].first;

        // Create groups based on the limit condition
        for (int i=1; i<n; i++) {
            const int x=nIdx[i].first;
            if (x-prev <= limit) 
                group.back().second=i;
            else 
                group.push_back({i, i});
            prev=x;
        }

        // Sort indices within each group and assign values to nums
        for (auto& se : group) {
            auto [s, e]=se;
            int sn=e-s+1;
            for (int i=s, j=0; i<=e; i++){
                auto& [x, idx]=nIdx[i];
                values[j]=x;
                seq[j++]=idx;
            }

            sort(seq, seq+sn);  
            for (int i=0; i<sn; i++) {
                nums[seq[i]]=values[i];
            }
        }

        return nums;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();