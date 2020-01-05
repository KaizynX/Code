#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+7;

int n, m, k;
int a[N], vis[N];

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        if (fx < fy) fa[fx] = fy;
        else fa[fy] = fx;
        return true;
    }
} dsu;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    dsu.init(n);

    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        int cur = i;
        ++k;
        while (!vis[cur]) {
            dsu.merge(i, cur);
            vis[cur] = 1;
            cur = a[cur];
        }
    }
    cout << abs(n-k-m) << endl;
    while (n-k < m) {
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (dsu[i] == dsu[j]) continue;
                cout << i << " " << j << " ";
                dsu.merge(i, j);
                flag = 1;
                break;
            }
            if (flag) break;
        }
        --k;
    }
    while (n-k > m) {
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (dsu[i] != dsu[j]) continue;
                cout << i << " " << j << " ";
                dsu.fa[i] = i;
                flag = 1;
                break;
            }
            if (flag) break;
        }
        ++k;
    }
    return 0;
}
