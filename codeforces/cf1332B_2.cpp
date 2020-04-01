/*
 * @Author: Kaizyn
 * @Date: 2020-03-31 21:46:55
 * @LastEditTime: 2020-03-31 23:14:53
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

int n;
int a[N], c[N];
vector<int> fac[N];
set<int> son[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    son[2].clear();
    for (int i = 3; i < 500; i += 2) son[i].clear();
    for (int i = 1, x; i <= n; ++i) {
        vector<int>().swap(fac[i]);
        x = a[i];
        for (int j = 2; j*j <= x; ++j) {
            if (x%j) continue;
            fac[i].emplace_back(j);
            son[j].insert(i);
            while (x%j == 0) x /= j;
        }
        if (x > 1) {
            fac[i].emplace_back(x);
            son[x].insert(i);
        }
    }
    int m = 0;
    while (++m) {
        int mx = 2;
        for (int i = 3; i < 500; i += 2) {
            if (son[i].size() > son[mx].size()) mx = i;
        }
        if (son[mx].size() == 0) break;
        for (int i : son[mx]) {
            c[i] = m;
            for (int j : fac[i]) {
                if (j != mx) son[j].erase(i);
            }
        }
        son[mx].clear();
    }
    cout << m-1 << "\n";
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