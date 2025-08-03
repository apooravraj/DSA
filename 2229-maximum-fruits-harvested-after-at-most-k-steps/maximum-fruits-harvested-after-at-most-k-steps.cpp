class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> prefixSum(n);
        vector<int> positions(n);

        for(int i = 0; i < n; i++) {
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFruits = 0;

        for(int d = 0; d <= k / 2; d++) {
            int remain = k - 2 * d;

            // Case 1: go left `d`, then right `remain`
            int i = startPos - d;
            int j = startPos + remain;

            int left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            int right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }

            // Case 2: go right `d`, then left `remain`
            i = startPos - remain;
            j = startPos + d;

            left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }
        }

        return maxFruits;
    }
};
