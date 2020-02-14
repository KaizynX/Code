#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n;
int a[N][N], row[N], col[N];

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) row[i] = col[i] = 0;
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
                row[i] += a[i][j];
                col[j] += a[i][j];
                if (i == j) c1 += a[i][j];
                if (i+j == n+1) c2 += a[i][j];
            }
        }
        int flag = c1 == c2;
        for (int i = 1; i <= n; ++i)
            flag &= c1 == row[i] && c1 == col[i];
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
