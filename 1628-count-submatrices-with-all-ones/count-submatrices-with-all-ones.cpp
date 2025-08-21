class Solution {
public:
    int onedArrayCount(vector<int>& vec) {
        int cons = 0;
        int subCount = 0;

        for (int &val : vec) {
            if (val == 0) {
                cons = 0;
            } else {
                cons++;
            }
            subCount += cons;
        }
        return subCount;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;

        // iterate over all possible startRows
        for (int startRow = 0; startRow < m; startRow++) {
            vector<int> vec(n, 1); // initially all 1s

            // extend downwards from startRow
            for (int endRow = startRow; endRow < m; endRow++) {
                for (int col = 0; col < n; col++) {
                    vec[col] &= mat[endRow][col];
                }
                result += onedArrayCount(vec);
            }
        }

        return result;
    }
};
