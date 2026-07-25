class Solution {
public:
    int maxProduct(int n) {
        int maxD=0, maxD2=0;
        for( ;n>0; n/=10){
            int D=n%10;
            if (D>=maxD)
                maxD2=exchange(maxD, D);
            else if (D>=maxD2)
                maxD2=D;
        }
        return maxD*maxD2;
    }
};