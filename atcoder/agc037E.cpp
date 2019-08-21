#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 5e3+7;

int n, k, maxl;
char minc = 'z';
string s, res;

inline void Ope(int p)
{
    int step = k, nowl = maxl;
    string S = s, U, T;
    if (step > 1 && p != n-1) {
        U = S;
        reverse(U.begin(), U.end());
        T = S+U;
        S = T.substr(n-p+nowl-1, n);
        --step;
    }
    for (int i = 1; i < step; ++i) {
        S = S.substr(nowl)+string(nowl, minc);
        nowl <<= 1;
        if (nowl >= n) {
            cout << string(n, minc) << endl;
            exit(0);
        }
    }
    // last step
    U = S;
    reverse(U.begin(), U.end());
    T = S+U;
    S = T.substr(n-nowl, n);
    res = min(res, S);
#ifdef DEBUG
    cout << p << " " << S << endl;
#endif
}

int main()
{
    cin >> n >> k >> s;
    res = s;
    for (char c : s) minc = min(minc, c);
    // special judge
    if (k >= 14) {
        cout << string(n, minc) << endl;
        return 0;
    }
    if (k == 1) {
        string S = s, U = s, T;
        reverse(U.begin(), U.end());
        T = S+U;
        for (int i = 1; i <= n; ++i) {
            if (T[i] == minc && T[i] != T[i-1]) {
                res = min(res, T.substr(i, n));
            }
        }
        cout << res << endl;
        return 0;
    }
    for (int i = 0, curl = 0; i < n; ++i) {
        if (s[i] == minc) {
            ++curl;
            maxl = max(maxl, curl);
        } else {
            curl = 0;
        }
    }
    for (int i = 0, curl = 0; i < n; ++i) {
        if (s[i] == minc) {
            if (++curl == maxl) {
                Ope(i);
            }
        } else {
            curl = 0;
        }
    }
    if (s[n-1] == minc) {
        int pp = n-1;
        maxl = 1;
        while (pp-1 >= 0 && s[pp-1] == minc) {
            ++maxl;
            --pp;
        }
        Ope(n-1);
    }
    cout << res << endl;
    return 0;
}
