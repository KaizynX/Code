#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;

int n, m, k;
int x[N], y[N], fx[N], fy[N];
int a[N][N], up[N][N], lif[N][N], rig[N][N];

inline void discrete()
{
    int sz = k+2;
    fx[k+1] = 0; fx[k+2] = n;
    fy[k+1] = 0; fy[k+2] = m;
    sort(fx+1, fx+sz+1);
    sort(fy+1, fy+sz+1);
    n = unique(fx+1, fx+sz+1)-fx;
    m = unique(fy+1, fy+sz+1)-fy;
    for (int i = 1; i <= k; ++i) {
        x[i] = lower_bound(fx+1, fx+n+1, x[i])-fx;
        y[i] = lower_bound(fy+1, fy+m+1, y[i])-fy;
        a[x[i]][y[i]] = 1;
    }
    fx[0] = fx[1]; fx[n+1] = fx[n];
    fy[0] = fy[1]; fy[m+1] = fy[m];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> x[i] >> y[i];
        fx[i] = x[i]; fy[i] = y[i];
    }
    discrete();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1][j]) up[i][j] = fx[i]-fx[i-1];
            else up[i][j] = up[i-1][j]+fx[i]-fx[i-1];
            if (a[i][j-1]) lif[i][j] = fy[j]-fy[j-1];
            else lif[i][j] = lif[i][j-1]+fy[j]-fy[j-1];
        }
        for (int j = m; j; --j) {
            if (a[i][j+1]) rig[i][j] = fy[j+1]-fy[j];
            else rig[i][j] = rig[i][j+1]+fy[j+1]-fy[j];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!a[i-1][j]) {
                lif[i][j] = min(lif[i][j], lif[i-1][j]);
                rig[i][j] = min(rig[i][j], rig[i-1][j]);
            }
            res = max(res, up[i][j]*(lif[i][j]+rig[i][j]-1));
        }
    }
    cout << res << endl;
    return 0;
}
