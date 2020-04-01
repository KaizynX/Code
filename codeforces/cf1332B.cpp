/*
 * @Author: Kaizyn
 * @Date: 2020-03-31 21:46:55
 * @LastEditTime: 2020-03-31 23:36:46
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

int n, m, k;
int a[N], b[N], c[N], vis[N];
vector<int> vec;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) b[i] = a[i], vis[i] = 0;
    sort(b+1, b+n+1);
    m = unique(b+1, b+n+1)-b-1;
    k = 0;
    for (int i = 1; i <= m; ++i) {
        if (vis[i]) continue;
        vec.clear();
        c[b[i]] = ++k;
        vec.emplace_back(b[i]);
        for (int j = i+1; j <= m; ++j) if (!vis[j]) {
            int flag = 1;
            for (int num : vec) if (__gcd(b[j], num) == 1) {
                flag = 0; break;
            }
            if (!flag) continue;
            vis[j] = 1;
            vec.emplace_back(b[j]);
            c[b[j]] = k;
        }
    }
    cout << k << "\n";
    for (int i = 1; i <= n; ++i) cout << c[a[i]] << " \n"[i==n];
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