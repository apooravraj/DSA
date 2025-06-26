class Solution {
public:
    int longestSubsequence(string s, int k) {
        int j = 0;
        int sum = 0;
        int ans = 0;

        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                ans++;
            } 
            else if (j < 31 && sum + (1 << j) <= k) {
                sum += (1 << j);
                ans++;
            }
            j++;
        }
        return ans;
    }
};
