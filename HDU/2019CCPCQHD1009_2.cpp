#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
const int c[3] = { 1, 4, 16 };

string str;
int str_len;
int dp[N][3][3][3], s[128];
// len i-2 i-1 i'th
// 0 - Q1 1 - W4 2 - E16

inline void init()
{
    s['Y'] = 3;
    s['V'] = 6;
    s['G'] = 18;
    s['C'] = 12;
    s['X'] = 9;
    s['Z'] = 24;
    s['T'] = 48;
    s['F'] = 33;
    s['D'] = 36;
    s['B'] = 21;
}

inline string ope(string &ss)
{
    string res = "";
    res += ss[0];
    for (int i = 1; i < str_len; ++i) {
        if (ss[i] == ss[i-1]) continue;
        res += ss[i];
    }
    return res;
}

int main()
{
    init();
    cin >> str;
    str_len = str.length();
    str = ope(str);
    for (int len = 3; len <= (int)str.length()*3; ++len) {
        for (int i1 = 0; i1 < 3; ++i1) {
            for (int j1 = 0; j1 < 3; ++j1) {
                for (int k1 = 0; k1 < 3; ++k1) {
                    int cur = c[i1]+c[j1]+c[k1], &now = dp[len][i1][j1][k1];
                    if (len > 3) for (int i2 = 0; i2 < 3; ++i2) {
                        if (len > 4) for (int j2 = 0; j2 < 3; ++j2) {
                            if (len > 5) for (int k2 = 0; k2 < 3; ++k2) {
                                int last3 = dp[len-3][i2][j2][k2];
                                now = max(now, last3+(cur == s[(int)str[last3] ? 1 : 0]));
                                if (now == (int)str.length()) {
                                    cout << len+str_len << endl;
                                    return 0;
                                }
                            }
                            int last2 = dp[len-2][i2][j2][i1];
                            now = max(now, last2+(cur == s[(int)str[last2]] ? 1 : 0));
                            if (now == (int)str.length()) {
                                cout << len+str_len << endl;
                                return 0;
                            }
                        }
                        int last1 = dp[len-1][i2][i1][j1];
                        now = max(now, last1+(cur == s[(int)str[last1]] ? 1 : 0));
                        if (now == (int)str.length()) {
                            cout << len+str_len << endl;
                            return 0;
                        }
                    }
                    now = max(now, now+(cur == s[(int)str[now]] ? 1 : 0));
                    if (now == (int)str.length()) {
                        cout << len+str_len << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
