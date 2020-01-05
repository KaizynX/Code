#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m;
int a[N][N];
int lif[N][N], rig[N][N], up[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            a[i][j] = c == 'F';
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) {
                up[i][j] = up[i-1][j]+1;
                lif[i][j] = lif[i][j-1]+1;
            }
        }
        for (int j = m; j; --j) {
            if (a[i][j]) {
                rig[i][j] = rig[i][j+1]+1;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1][j]) {
                lif[i][j] = min(lif[i][j], lif[i-1][j]);
                rig[i][j] = min(rig[i][j], rig[i-1][j]);
            }
            res = max(res, up[i][j]*(rig[i][j]+lif[i][j]-1));
        }
    }
    cout << 3*res << endl;
    return 0;
}
