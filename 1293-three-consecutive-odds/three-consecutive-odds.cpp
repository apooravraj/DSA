class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCount = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 != 0) {
                oddCount++;
                if (oddCount == 3) {
                    return true;
                }
            } else {
                oddCount = 0;
            }
        }
        return false;
    }
};
