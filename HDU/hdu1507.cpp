#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m, k;
int a[N*N], odd[N*N], even[N*N];
map<int, int> vis;

inline bool _check(const int &u, const int &v);
bool check(const int &u);

inline bool _check(const int &u, const int &v) {
    if (a[v] || vis.count(v)) return false;
    vis[v] = 1;
    if (odd[v] == -1 || check(odd[v])) {
        odd[v] = u;
        even[u] = v;
        return true;
    }
    return false;
}

bool check(const int &u) {
    if (u%m != 0 && _check(u, u-1)) return true;
    if (u%m != m-1 && _check(u, u+1)) return true;
    if (u/m != 0 && _check(u, u-m)) return true;
    if (u/m != n-1 && _check(u, u+m)) return true;
    return false;
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2 && n|m) {
        vector<int> res;
        scanf("%d", &k);
        memset(a, 0, sizeof(int)*(n*m));
        memset(odd, -1, sizeof(int)*(n*m));
        for (int i = 0, x, y; i < k; ++i) {
            scanf("%d %d", &x, &y);
            --x; --y;
            a[x*m+y] = 1;
        }
        for (int i = 0; i < n*m; ++i) {
            if (((i/m+i%m)&1) || a[i]) continue;
            vis.clear();
            if (check(i)) res.emplace_back(i);
        }
        cout << res.size() << endl;
        for (int i : res)
            printf("(%d,%d)--(%d,%d)\n", i/m+1, i%m+1, even[i]/m+1, even[i]%m+1);
        putchar('\n');
    }
    return 0;
}
