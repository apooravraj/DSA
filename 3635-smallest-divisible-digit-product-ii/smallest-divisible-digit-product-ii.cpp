class Solution {
public:
    string smallestNumber(string num, long long t) {
        int need[4] = {0, 0, 0, 0};
        const int pr[4] = {2, 3, 5, 7};
        for (int j = 0; j < 4; ++j)
            while (t % pr[j] == 0) { t /= pr[j]; ++need[j]; }
        if (t != 1) return "-1";

        static const int DE[10][4] = {
            {0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},
            {0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}
        };
        auto pack = [](const int r[4]) {
            int eight = r[0] / 3, mod = r[0] % 3;
            int nine = r[1] / 2, three = r[1] % 2;
            int two = (mod == 1), four = (mod == 2), six = 0;
            if (two && three) { six = 1; two = three = 0; }
            if (three && four) { two = six = 1; three = four = 0; }
            string s;
            s.append(two, '2');   s.append(three, '3'); s.append(four, '4');
            s.append(r[2], '5');  s.append(six, '6');   s.append(r[3], '7');
            s.append(eight, '8'); s.append(nine, '9');
            return s;
        };
        auto minLen = [&](const int r[4]) { return (int)pack(r).size(); };

        int n = num.size();
        vector<array<int,4>> pre(n + 1);
        pre[0] = {0, 0, 0, 0};
        int z = n;
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            if (d == 0 && z == n) z = i;
            for (int j = 0; j < 4; ++j)
                pre[i+1][j] = min(pre[i][j] + DE[d ? d : 1][j], need[j]);
        }

        auto fill = [&](int k, const int r0[4]) {
            int cur[4] = {r0[0], r0[1], r0[2], r0[3]};
            string s;
            s.reserve(k);
            for (int p = 0; p < k; ++p) {
                int left = k - 1 - p;
                for (int d = 1; d <= 9; ++d) {
                    int nr[4];
                    for (int j = 0; j < 4; ++j) nr[j] = max(0, cur[j] - DE[d][j]);
                    if (minLen(nr) <= left) {
                        s += char('0' + d);
                        memcpy(cur, nr, sizeof cur);
                        break;
                    }
                }
            }
            return s;
        };

        if (z == n) {
            bool ok = true;
            for (int j = 0; j < 4; ++j) if (pre[n][j] < need[j]) ok = false;
            if (ok) return num;
        }

        for (int i = min(z, n - 1); i >= 0; --i)
            for (int d = num[i] - '0' + 1; d <= 9; ++d) {
                int r[4];
                for (int j = 0; j < 4; ++j)
                    r[j] = max(0, need[j] - pre[i][j] - DE[d][j]);
                if (minLen(r) <= n - 1 - i)
                    return num.substr(0, i) + char('0' + d) + fill(n - 1 - i, r);
            }

        string tail = pack(need);
        int L = max(n + 1, (int)tail.size());
        return string(L - tail.size(), '1') + tail;
    }
};