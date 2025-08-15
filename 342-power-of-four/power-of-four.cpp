class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && n==bit_ceil((unsigned)n) && (countl_zero((unsigned)n)&1);
    }
};