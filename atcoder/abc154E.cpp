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
    if (q > p) return 0;
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

inline void solve()
{
    cin >> s >> k;

    int res = pow9(k)*C(s.size()-1, k);
    for (int i = 0, j = 0; i < (int)s.size(); ++i) {
        if (s[i] != '0') {
            ++j;
            if (j == k) {
                res += s[i]-'0';
                break;
            }
            res += (s[i]-'1')*pow9(k-j)*C(s.size()-i-1, k-j);
        }
    }
    cout << res << endl;
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