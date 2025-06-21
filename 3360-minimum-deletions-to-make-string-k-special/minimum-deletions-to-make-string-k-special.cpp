class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);

        for(char &ch : word) {
            freq[ch-'a']++;
        }
        sort(begin(freq), end(freq));

        int result = word.length();
        int cumulative_deleted = 0;

        for(int i = 0; i < 26; i++) {

            int del = cumulative_deleted;
            for(int j = 25; j > i; j--) {
                if(freq[j] - freq[i] <= k) {
                    break;
                }
                del += freq[j] - freq[i] - k;

            }
            result = min(result, del);
            cumulative_deleted+= freq[i];


        }
        return result;
        
    }
};