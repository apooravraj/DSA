class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> st(101, -1);  // tracks whether number is already added
        int sum = 0;
        int maxNeg = INT_MIN;

        for (int &num : nums) {
            if (num <= 0) {
                maxNeg = max(maxNeg, num);
            } 
            else if (num <= 100 && st[num] == -1) {  // bounds check added
                sum += num;
                st[num] = 1;
            }
        }

        return sum == 0 ? maxNeg : sum;
    }
};
