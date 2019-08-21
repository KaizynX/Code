#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int n, res = -1;
long long a[kN];
int vis[kN];
vector<long long> v[80];

void dfs(int cur, int dep)
{
    if (vis[cur]) {
        int now = dep-vis[cur];
        if (now > 2) {
            if (res == -1) res = now;
            else res = min(res, now);
        }
        return;
    }
    vis[cur] = dep;
    for (int i = 1; i <= n; ++i) {
        if (cur == i) continue;
        if (a[i]&a[cur]) dfs(i, dep+1);
    }
    vis[cur] = 0;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!a[i]) {
            --i, --n;
            continue;
        }
        for (int j = 0; j < 63; ++j) {
            if (a[i]&(1ll<<j)) v[j].push_back(a[i]);
        }
    }
    for (int i = 0; i < 63; ++i) {
        if (v[i].size() >= 3) {
            cout << 3 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, 1);
    }
    cout << res << endl;
    return 0;
}
