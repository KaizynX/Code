#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int M = 1e1+7;

int n, m, w;
int ac[N][M], tr[N][M], mxtr[N][M], res[N], cnt[M], sub[N], sol[N];

int main()
{
    cin >> n >> m >> w;
    for (int i = 1, x, y, c; i <= w; ++i) {
        cin >> x >> y >> c;
        ++sub[x];
        if (c) {
            ac[x][y] |= 1;
            tr[x][y] = 0;
        } else {
            mxtr[x][y] = max(mxtr[x][y], ++tr[x][y]);
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cnt[j] += ac[i][j];
            sol[i] += ac[i][j];
        }
    for (int i = 1; i <= n; ++i) {
        if (!sub[i]) res[i] = 998244353;
        else if (sub[i] && !sol[i]) res[i] = 1000000;
        else if (sol[i] == m) res[i] = 0;
        else {
            for (int j = 1; j <= m; ++j) {
                if (cnt[j] && !ac[i][j]) res[i] += 20;
                if (cnt[j] >= n/2 && !ac[i][j]) res[i] += 10;
                res[i] += mxtr[i][j]*mxtr[i][j];
                if (!ac[i][j]) res[i] += mxtr[i][j]*mxtr[i][j];
            }
        }
        cout << res[i] << endl;
    }
    return 0;
}
