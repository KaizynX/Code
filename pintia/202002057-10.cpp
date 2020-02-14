#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, maxd;
int a[N], d[N];

int dfs(int u)
{
    if (d[u]) return d[u];
    return d[u] = dfs(a[u])+1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == -1) d[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) dfs(i);
        maxd = max(maxd, d[i]);
    }
    cout << maxd << endl;
    for (int i = 1, flag = 0; i <= n; ++i) {
        if (d[i] != maxd) continue;
        if (flag) cout << " ";
        flag = 1;
        cout << i;
    }
    cout << endl;
    return 0;
}
