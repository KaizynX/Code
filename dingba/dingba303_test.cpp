#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int INF = 1e9;

int n, res;
int a[N], c[N], h[N];

void dfs(int u)
{
    if (u > n) {
        for (int i = 1; i <= c[n]; ++i) h[i] = 0;
        for (int i = 1; i <= n; ++i) h[c[i]] += a[i];
        for (int i = 1; i < c[n]; ++i) if (h[i] < h[i+1]) return;
        if (c[n] <= res) return;
        res = c[n];
        for (int i = 1; i <= c[n]; ++i) cout << h[i] << " \n"[i==c[n]];
        return;
    }
    c[u] = c[u-1];
    dfs(u+1);
    c[u] = c[u-1]+1;
    dfs(u+1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    c[0] = 1;
    dfs(1);
    cout << res << endl;
    return 0;
}
