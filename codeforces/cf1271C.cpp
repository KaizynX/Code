#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int d[] = {0, -1, 0, 1, 0};
const int INF = 1e9;

int n, sx, sy;
int c[4];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> sx >> sy;
    for (int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        if (x < sx) ++c[1];
        if (x > sx) ++c[3];
        if (y < sy) ++c[0];
        if (y > sy) ++c[2];
    }
    int res = -1;
    for (int i = 0, nx, ny; i < 4; ++i) {
        nx = sx+d[i];
        ny = sy+d[i+1];
        if (nx < 0 || ny < 0 || nx > INF || ny > INF) continue;
        if (res == -1 || c[i] > c[res]) res = i;
    }
    cout << c[res] << endl;
    cout << sx+d[res] << " " << sy+d[res+1] << endl;
    return 0;
}

