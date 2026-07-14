const int N=201, mod=1e9+7;
int GCD[N][N];
int dp[2][N*N];
using ll=long long;
class Solution {
public:
    static void computeGCD(){
        if (GCD[0][1]==1) return;
        for(int x=0; x<N; x++) 
            GCD[x][x]=GCD[x][0]=GCD[0][x]=x;
        for(int x=1; x<N; x++){
            GCD[x][1]=GCD[1][x]=1;
            for(int y=2; y<x; y++){
                GCD[x][y]=GCD[y][x]=GCD[y][x-y];
            }
        }
    }
    static int subsequencePairCount(vector<int>& nums) {
        computeGCD();
        const int M=ranges::max(nums), M2=(M+1)*(M+1);
        memset(dp[0], 0, sizeof(int)*M2);
        dp[0][0]=1;
        const int n=nums.size();
        for(int i=0; i<n; i++){
            const int x=nums[i];
            bool cur=i&1, nxt=!cur;
            memset(dp[nxt], 0, sizeof(int)*M2);

            for(int g1=0; g1<=M; g1++){
                for(int g2=0; g2<=M; g2++){
                    if (dp[cur][g1*(M+1)+g2]==0) continue;
                    ll curDp=dp[cur][g1*(M+1)+g2];
                    const int ng1=GCD[g1][x];
                    dp[nxt][ng1*(M+1)+g2]=(dp[nxt][ng1*(M+1)+g2]+curDp)%mod;

                    const int ng2=GCD[g2][x];
                    dp[nxt][g1*(M+1)+ng2]=(dp[nxt][g1*(M+1)+ng2]+curDp)%mod;

                    dp[nxt][g1*(M+1)+g2]=(dp[nxt][g1*(M+1)+g2]+curDp)%mod;
                }
            }
        }
        bool last=n&1;
        ll ans=0;
        for(int i=1; i<=M; i++) ans+=dp[last][i*(M+2)];
        return ans%mod;
    }
};