class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;

        for(char hor : {'E', 'W'}) {
            for(char ver : {'N', 'S'}) {
                int remainingK = k;
                int netX = 0, netY = 0;

                for(char ch : s) {
                    if(ch == hor && remainingK > 0) {
                        ch = (ch == 'W') ? 'E' : 'W';
                        remainingK--;
                    } else if(ch == ver && remainingK > 0) {
                        ch = (ch == 'N') ? 'S' : 'N';
                        remainingK--;
                    }

                    if(ch == 'E') netX++;
                    if(ch == 'W') netX--;
                    if(ch == 'N') netY++;
                    if(ch == 'S') netY--;

                    ans = max(ans, abs(netX) + abs(netY));
                }
            }
        }

        return ans;
    }
};
