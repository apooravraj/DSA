class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n=len(grid), len(grid[0])
        lim=(n+m)>>1
        if ((m+n)&1)==0 or grid[0][0]==')' or grid[m-1][n-1]=='(':
            return False
        maxMask=(1<<(lim+1))-1
        dp=[0]*n

        dp[0]=1<<1
        p=1
        for j in range(1, n):
            p+=(grid[0][j]=='(')-(grid[0][j]==')')
            if p<0 or p>lim: break
            dp[j]=1<<p
        p=1
        for i in range(1, m):
            p+=(grid[i][0]=='(')-(grid[i][0]==')')
            if dp[0]==0 or p<0 or p>lim: dp[0]=0
            else: dp[0]=1<<p
            for j in range(1, n):
                dp[j]=dp[j-1]|dp[j]
                dp[j]=(dp[j]<<1)& maxMask if grid[i][j]=='(' else dp[j]>>1
        return dp[-1]&1==1