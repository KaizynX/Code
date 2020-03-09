#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e6+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n;
string s;

inline void solve()
{
    cin >> n >> s;
    int l = 0, r = 0, res = 0;
    int i = 0, j = s.size()-1;
    while (i <= j && s[i] == 'L') ++i, ++res;
    while (i <= j && s[j] == 'R') --j, ++res;
    /*
    for (int k = i; k <= j; ++k) {
        if (s[k] == 'L') ++l;
        if (s[k] == 'R') ++r;
    }
    res += abs(l-r);
    */
    if (i <= j) ++res;
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