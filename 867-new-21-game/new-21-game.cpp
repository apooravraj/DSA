class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> P(n+1, 0.0);

        P[0] = 1;

        double currProbabSum = (k == 0) ? 0 : 1;
        for(int i =1; i <=n; i++) {
            P[i] = currProbabSum/maxPts;

            if(i < k)
            currProbabSum += P[i];

            if(i-maxPts >= 0 && i-maxPts < k)
            currProbabSum -= P[i-maxPts];
        }
        return accumulate(begin(P) + k, end(P), 0.0);
        
    }
};