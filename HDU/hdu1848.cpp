#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;

int n, m, p, numf;
int f[N+7], sg[N+7];

inline void init()
{
    f[1] = 1;
    f[2] = 2;
    for (numf = 3; f[numf-1] <= N; ++numf) {
        f[numf] = f[numf-1]+f[numf-2];
    }
    --numf;
}

inline void getSG()
{
    static int vis[N+7];
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= numf && i-f[j] >= 0; ++j) {
            vis[sg[i-f[j]]] = 1;
        }
        for (int j = 0; ; ++j) {
            if (!vis[j]) {
                sg[i] = j;
                break;
            }
        }
        for (int j = 1; j <= numf && i-f[j] >= 0; ++j) {
            vis[sg[i-f[j]]] = 0;
        }
    }
}

int main()
{
    init();
    getSG();
    while (cin >> m >> n >> p) {
        if (!m && !n && !p) break;
        puts((sg[m]^sg[n]^sg[p] ? "Fibo" : "Nacci"));
    }
    return 0;
}
