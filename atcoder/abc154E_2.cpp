#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int k;
string s;

inline int C(const int &p, const int &q)
{
    if (q > p || !q) return 0;
    int res = 1;
    for (int i = p; i > p-q; --i) res *= i;
    for (int i = 2; i <= q; ++i) res /= i;
    return res;
}

inline int pow9(const int &p)
{
    int res = 1;
    for (int i = 1; i <= p; ++i) res *= 9;
    return res;
}

inline int f(int i, const int &kk)
{
    while (i < (int)s.size() && s[i] == '0') ++i;
    if (i >= (int)s.size()) return 0;
    int res = pow9(kk)*C(s.size()-i-1, kk)+
        (s[i]-'1')*pow9(kk-1)*C(s.size()-i-1, kk-1);
    #ifdef DEBUG
    cout << s[i]-'1' << " " << pow9(kk-1) << " " << C(s.size()-i, kk-1) << endl;
    cout << res << endl;
    #endif
    return res+(kk == 1 ? s[i]-'0' : f(i+1, kk-1));
}

inline void solve()
{
    cin >> s >> k;
    cout << f(0, k) << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}