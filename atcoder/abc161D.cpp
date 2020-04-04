/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 20:17:16
 * @LastEditTime: 2020-04-04 21:31:36
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int k;
int f[20][12], s[20];
// f[i][j] start with j, length i
int res[20];

void dfs(const int &u, const int &val)
{
    if (!u) return;
    int v = (val < k), nex = val;
    for (int i = 1; i <= 9; ++i) {
        if (nex+f[u][i] < k) {
            nex += f[u][i];
            v = i+1;
        } else if (nex+f[u][i] == k) {
            nex += f[u][i];
            v = i;
        }
    }
    res[u] = v;
    dfs(u-1, nex);
}

inline void solve()
{
    cin >> k;
    if (k < 10) return void(cout << k << endl);
    for (int i = 0; i <= 9; ++i) f[1][i] = 1;
    s[1] = 9;
    for (int i = 2; i <= 12; ++i) {
        f[i][0] += f[i-1][0]+f[i-1][1];
        f[i][9] += f[i-1][9]+f[i-1][8];
        s[i] = s[i-1]+f[i][9];
        for (int j = 1; j <= 8; ++j) {
            f[i][j] += f[i-1][j-1]+f[i-1][j]+f[i-1][j+1];
            s[i] += f[i][j];
        }
    }
    #ifdef DEBUG
    for (int i = 1; i <= 12; ++i) {
        for (int j = 0; j <= 9; ++j) {
            cout << f[i][j] << " \n"[j==9];
        }
    }
    for (int i = 1; i <= 12; ++i) cout << s[i] << " \n"[i==12];
    #endif
    int len = 0, u = 1;
    while (s[len] < k) ++len;
    // dfs(len, s[len-1]);
    k -= s[len-1];
    while (k > f[len][u]) {
        k -= f[len][u];
        ++u;
    }
    res[len] = u;
    for (int i = len-1, l, r; i; --i) {
        l = max(0, res[i+1]-1);
        r = min(9, res[i-1]+1);
        u = l;
        while (k > f[i][u]) {
            k -= f[i][u];
            ++u;
        }
        res[i] = u;
    }
    for (int i = len; i; --i) cout << res[i];
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}