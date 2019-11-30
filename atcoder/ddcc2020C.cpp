#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+7;

int n, m, num, cnt;
int a[N][N], res[N][N];

int main()
{
    cin >> n >> m >> num;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            a[i][j] = (c == '#' ? 1 : 0);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) {
                ++cnt;
                res[i][j] = cnt;
                for (int k = j-1; k; --k) {
                    if (res[i][k] || a[i][k]) break;
                    res[i][k] = cnt;
                }
                for (int k = j+1; k <= m; ++k) {
                    if (res[i][k] || a[i][k]) break;
                    res[i][k] = cnt;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!res[i][1]) continue;
        for (int k = i-1; k; --k) {
            if (res[k][1]) break;
            for (int j = 1; j <= m; ++j)
                res[k][j] = res[i][j];
        }
        for (int k = i+1; k <= n; ++k) {
            if (res[k][1]) break;
            for (int j = 1; j <= m; ++j)
                res[k][j] = res[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

