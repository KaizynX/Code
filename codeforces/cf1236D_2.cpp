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
        // if (lx == rx && ly == ry) break;
        int tmp = -1;
        if (nd == 0) { // right
            //if (ly == ry) break;
            for (int i = 0; i < (int)vx[lx].size(); ++i) {
                if (vx[lx][i] >= ly && vx[lx][i] <= ry) {
                    tmp = i;
                    break;
                }
            }
            if (tmp != -1) ry = vx[lx][tmp]-1;
            //if (flag && ry == ly) break;
            //flag = ry == ly;
            res += ry-ly+1;
            ++lx;
        } else if (nd == 1) { // down
            //if (lx == rx) break;
            for (int i = 0; i < (int)vy[ry].size(); ++i) {
                if (vy[ry][i] >= lx && vy[ry][i] <= rx) {
                    tmp = i;
                    break;
                }
            }
            if (tmp != -1) rx = vy[ry][tmp]-1;
            //if (flag && rx == lx) break;
            //flag = rx == lx;
            res += rx-lx+1;
            --ry;
        } else if (nd == 2) { // left
            //if (ly == ry) break;
            for (int i = (int)vx[rx].size()-1; i >= 0; --i) {
                if (vx[rx][i] >= ly && vx[rx][i] <= ry) {
                    tmp = i;
                    break;
                }
            }
            if (tmp != -1) ly = vx[rx][tmp]+1;
            //if (flag && ry == ly) break;
            //flag = ry == ly;
            res += ry-ly+1;
            --rx;
        } else if (nd == 3) { // up
            //if (lx == rx) break;
            for (int i = (int)vy[ly].size()-1; i >= 0; --i) {
                if (vy[ly][i] >= lx && vy[ly][i] <= rx) {
                    tmp = i;
                    break;
                }
            }
            if (tmp != -1) lx = vy[ly][tmp]+1;
            //if (flag && rx == lx) break;
            //flag = rx == lx;
            res += rx-lx+1;
            ++ly;
        }
        nd = (nd+1)%4;
#ifdef DEBUG
        printf("%d:[%d,%d],[%d,%d]\n", nd, lx, rx, ly, ry);
#endif
    }
#ifdef DEBUG
    cout << sum << " " << res << endl;
#endif
    cout << (sum == res ? "Yes" : "No") << endl;
    return 0;
}
