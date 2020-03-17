/*
 * @Author: Kaizyn
 * @Date: 2020-03-17 16:46:57
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-17 19:08:05
 * @FilePath: \Code\Luogu\luogu2962.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 40;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

// -1 : no solution, 0 : multi , 1 : one
template <typename T>
int XorGauss(T a[N][N], const int &n)
{
    int flag = 1;
    for (int i = 1, j, k; i <= n; ++i) {
        for (k = i; !a[k][i] && k <= n; ++k) {}
        if (k > n) {
            if (a[i][n+1]) return -1;
            flag = 0; continue;
        }
        swap(a[k], a[i]);
        for (j = 1; j <= n; ++j) if (i != j && a[j][i])
            for (k = i; k <= n+1; ++k) a[j][k] ^= a[i][k];
    }
    return flag;
}

int n, m, res;
int a[N][N], used[N];

void dfs(const int &u, const int &num)
{
    if (num >= res) return;
    if (u <= 0) { res = num; return; }
    if (a[u][u]) {
        int t = a[u][n+1];
        for (int i = u+1; i <= n; ++i) {
            if (a[u][i]) t ^= used[i];
        }
        dfs(u-1, num+t);
    } else {
        dfs(u-1, num);
        used[u] = 1;
        dfs(u-1, num+1);
        used[u] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) a[i][n+1] = a[i][i] = 1;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    if (XorGauss(a, n)) {
        for (int i = 1; i <= n; ++i) res += a[i][n+1];
    } else {
        res = INF;
        dfs(n, 0);
    }
    cout << res << endl;
    return 0;
}