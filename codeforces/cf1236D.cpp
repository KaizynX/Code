#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int dx[4] = { 0, 1, 0, -1 },
          dy[4] = { 1, 0, -1, 0 };

int n, m, k;
long long sum, res;
vector<int> vx[N], vy[N];

int main()
{
    cin >> n >> m >> k;
    sum = 1ll*n*m-k;
    for (int i = 1, x, y; i <= k; ++i) {
        cin >> x >> y;
        vx[x].push_back(y);
        vy[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        sort(vx[i].begin(), vx[i].end());
    }
    for (int i = 1; i <= m; ++i) {
        sort(vy[i].begin(), vy[i].end());
    }
    int lx = 1, rx = n, ly = 1, ry = m, nd = 0;// flag = 0;
    while (lx <= rx && ly <= ry) {
        ;
    }
    cout << (sum == res ? "Yes" : "No") << endl;
    return 0;
}
