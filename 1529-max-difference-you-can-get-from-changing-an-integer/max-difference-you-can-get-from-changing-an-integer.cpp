class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        // Maximize str1: replace the first non-9 digit with 9
        int idx = str1.find_first_not_of('9');
        if (idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        // Minimize str2
        bool replaced = false;
        for (int i = 0; i < str2.length(); i++) {
            char ch = str2[i];
            if (i == 0 && ch != '1') {
                replace(begin(str2), end(str2), ch, '1');
                replaced = true;
                break;
            } else if (i > 0 && ch != '0' && ch != str2[0]) {
                replace(begin(str2), end(str2), ch, '0');
                replaced = true;
                break;
            }
        }

        return stoi(str1) - stoi(str2);
    }
};
