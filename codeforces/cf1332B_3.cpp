/*
 * @Author: Kaizyn
 * @Date: 2020-04-01 09:45:41
 * @LastEditTime: 2020-04-01 09:53:33
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int a[N], c[N];
map<int, int> col;

inline int get_fac(const int &x)
{
    for (int i = 2; i*i <= x; ++i) if (x%i == 0) return i;
    return x;
}

inline int get_col(const int &x)
{
    if (col.count(x)) return col[x];
    else return col[x] = ++m;
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    m = 0;
    col.clear();
    for (int i = 1; i <= n; ++i) {
        c[i] = get_col(get_fac(a[i]));
    }
    cout << m << "\n";
    for (int i = 1; i <= n; ++i) cout << c[i] << " \n"[i==n];
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}