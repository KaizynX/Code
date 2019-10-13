#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int M = 50;

int n, m, res;
int p[N], vis[N][N], a[M], b[M];

inline void clear()
{
    for (int i = 1; i <= 6; ++i) {
        vis[i][7] = vis[7][i] = 1;
        for (int j = 1; j <= 6; ++j) {
            vis[i][j] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
    }
    do {
        clear();
        int now = 0;
        for (int i = 1; i <= m; ++i) {
            if (!vis[p[a[i]]][p[b[i]]]) ++now;
            vis[p[a[i]]][p[b[i]]] = vis[p[b[i]]][p[a[i]]] = 1;
        }
        res = max(res, now);
    } while (next_permutation(p+1, p+n+1));
    cout << res << endl;
    return 0;
}
