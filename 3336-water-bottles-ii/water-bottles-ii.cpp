class Solution {
public:
    int maxBottlesDrunk(int n, int k) {
        return n+((-2*k+3+sqrt(4*k*k+8*n-12*k+1))/2);
    }
};