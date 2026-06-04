int D[6];// least significant digit first
class Solution {
public:
    static int wav(int x){
        int d;
        for(d=0 ; x>0; x/=10, d++){
            D[d]=x%10;
        }
        int cnt=0, prv=D[0], nxt=D[1];
        for(int i=1; i<d-1; i++){
            int cur=exchange(nxt, D[i+1]);
            cnt+=(((prv<cur) & (cur>nxt)) || ((prv>cur) & (cur<nxt)));
            prv=cur;
        }
        return cnt;
    }
    static int totalWaviness(int num1, int num2) {
        num1=max(num1, 101);
        int ans=0;
        for(int x=num1; x<=num2; x++)
            ans+=wav(x);
        return ans;
    }
};