class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int , vector<int>> mp;

        // Store elements by diagonals
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i - j;
                mp[diag].push_back(grid[i][j]);
            }
        }

        // Sort each diagonal
        for(auto &it : mp) {
            if(it.first >= 0) {
                sort(it.second.begin(), it.second.end());
            } else {
                sort(it.second.rbegin(), it.second.rend());
            }
        }

        // Refill grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i - j;
                grid[i][j] = mp[diag].back();
                mp[diag].pop_back();
            }
        }

        return grid;
    }
};
