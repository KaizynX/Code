#include <bits/stdc++.h>

using namespace std;

const int N = 30;

string s;

inline void rev(string &str, int p)
{
    for (int i = p-1; i <= p+1; ++i) {
        if (i >= 0 && p < (int)str.length())
            str[i] ^= 1;
    }
}

inline int solve(string str)
{
    int cnt = 0;
    for (int i = 1; i < (int)str.length(); ++i) {
        if (str[i-1]) {
            rev(str, i);
            ++cnt;
        }
    }
    return str.back() ? -1 : cnt;
}

int main()
{
    while (cin >> s) {
        int res = -1;
        for (int i = 0; i < (int)s.length(); ++i) s[i] -= '0';
        res = solve(s);
        rev(s, 0);
        int tmp = solve(s);
        if (tmp != -1) res = res == -1 ? tmp+1 : min(res, tmp+1);
        if (res == -1) cout << "NO" << endl;
        else cout << res << endl;
    }
    return 0;
}
