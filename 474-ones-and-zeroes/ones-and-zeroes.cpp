// global C-array version with elapsed time: 26ms
short dp[101][101];
class Solution {
public:
    static int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0; i<=m; i++)
            memset(dp[i], 0, sizeof(short)*(n+1));
        for (auto& s: strs){
            const int len=s.size();
            const int c0=count(s.begin(), s.end(), '0'), c1=len-c0;
            for(int i=m; i>=c0; i--)
			    for(int j=n; j>=c1; j--)                    
				    dp[i][j]=max(dp[i][j], 
						    (short)(dp[i-c0][j-c1]+1));
        }
        return dp[m][n];
    }
};
static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();