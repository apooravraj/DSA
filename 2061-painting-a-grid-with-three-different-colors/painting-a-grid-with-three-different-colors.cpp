class Solution {
public:
    const int M = 1e9 + 7;
    vector<string> columnStates;
    
    // Helper to generate all valid column states (no same adjacent colors)
    void generateColumnStates(string curr, char prevChar, int l, int m) {
        if (l == m) {
            columnStates.push_back(curr);
            return;
        }

        for (char c = '0'; c < '3'; ++c) {
            if (c != prevChar) {
                generateColumnStates(curr + c, c, l + 1, m);
            }
        }
    }

    // Memoization table
    unordered_map<int, unordered_map<int, int>> dp;

    int solve(int remainCols, int prevIdx, int m) {
        if (remainCols == 0) return 1;
        if (dp[remainCols].count(prevIdx)) return dp[remainCols][prevIdx];

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for (int i = 0; i < columnStates.size(); i++) {
            string currState = columnStates[i];
            bool valid = true;

            for (int j = 0; j < m; j++) {
                if (prevState[j] == currState[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ways = (ways + solve(remainCols - 1, i, m)) % M;
            }
        }

        return dp[remainCols][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        generateColumnStates("", '#', 0, m);
        int result = 0;

        for (int i = 0; i < columnStates.size(); i++) {
            result = (result + solve(n - 1, i, m)) % M;
        }

        return result;
    }
};
