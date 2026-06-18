class Solution {
public:
    double angleClock(int h, int m) {
        return min(360-abs(h*30.0-m*5.5), abs(h*30.0-m*5.5));
    }
};