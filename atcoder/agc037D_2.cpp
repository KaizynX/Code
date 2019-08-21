#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;

int n, m;
int a[kN][kN], sort_a[kN], vis[kN], co[kN];
vector<int> v[kN][kN];

inline void print()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int cur)
{
    for (int i = 1; i <= n; ++i) {
        if (!v[cur][i].size() || vis[i]) continue;
        vis[i] = 1;
        if (!co[i] || check(co[i])) {
            co[i] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            int group = (a[i][j]-1)/m+1;
            v[i][group].push_back(a[i][j]);
        }
    }
    for (int j = 1; j <= m; ++j) {
        memset(co, 0, sizeof co);
        for (int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            check(i);
        }
        for (int i = 1; i <= n; ++i) {
            a[i][j] = v[i][co[i]].back();
            v[i][co[i]].pop_back();
        }
    }
    print();
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            sort_a[i] = a[i][j];
        }
        sort(sort_a+1, sort_a+n+1);
        for (int i = 1; i <= n; ++i) {
            a[i][j] = sort_a[i];
        }
    }
    print();
    return 0;
}
