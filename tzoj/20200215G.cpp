#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int n;
int x[N], y[N];
int a[N][N];

int main()
{
    while (cin >> x[1] >> y[1]) {
        memset(a, 0, sizeof a);
        a[x[1]][y[1]] = 1;
        for (int i = 2; i <= 3; ++i) {
            cin >> x[i] >> y[i];
            a[x[i]][y[i]] = 1;
        }
        int flag = 0;
        for (int i = 1, cnt; i <= 3; ++i) {
            cnt = 0;
            for (int j = 1; j <= 3; ++j)
                cnt += a[i][j];
            if (cnt == 3) { flag = 1; break; }
            cnt = 0;
            for (int j = 1; j <= 3; ++j)
                cnt += a[j][i];
            if (cnt == 3) { flag = 1; break; }
        }
        if (a[1][1] && a[2][2] && a[3][3]) flag = 1;
        if (a[1][3] && a[2][2] && a[3][1]) flag = 1;
        cout << (flag ? "Win" : "Continue") << endl;
    }
    return 0;
}
