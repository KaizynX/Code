#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e2+7;
const int INF = 1e9;

char a[N];
int nex[N][N], vis[N][N], res[N];
vector<int> last[N][N];

int main()
{
    scanf("%s", a+1);
    int n = strlen(a+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            nex[i][j] = 0;
            vis[i][j] = 0;
            vector<int>().swap(last[i][j]);
        }
        res[i] = 0;
        last[1][i].emplace_back(0);
    }
    for (int l = 1, r, i, p, flag; l <= n; ++l) {
        for (r = l; r <= n; ++r) {
            flag = 0;
            p = l;
            while (p < r && a[p] == '0') ++p;
            i = r+1;
            while (i <= n && a[i] == '0') ++i;
            for (; i <= n; ++i) {
                if (!flag) {
                    if (a[i] > a[p]) flag = 1;
                    if (a[i] < a[p]) flag = -1;
                }
                ++p;
                if (p <= r) continue;
                if (flag == 1) break;
                else {
                    ++i;
                    break;
                }
            }
            nex[l][r] = i;
#ifdef DEBUG
            printf("nex[%d][%d]=%d\n", l, r, nex[l][r]);
#endif
        }
    }
    for (int l = 2, r; l <= n; ++l) {
        for (r = l; r <= n; ++r) {
            for (int i = 1; i < l; ++i) {
                if (nex[i][l-1] <= r && last[i][l-1].size()) {
                    last[l][r].emplace_back(i);
                }
            }
        }
    }
    for (int i = n; i; --i) {
        if (last[i][n].size()) {
            vis[i][n] = 1;
            while (i && a[i-1] == '0') {
                --i;
                vis[i][n] = 1;
            }
            break;
        }
    }
    for (int l = n, r; l; --l) {
        for (r = n; r >= l; --r) {
            if (vis[l][r]) {
                for (int i : last[l][r]) {
                    vis[i][l-1] = 1;
                }
            }
        }
    }
    for (int i = 1, j; i <= n; i = j+1) {
        for (j = n; j >= i; --j) {
            if (vis[i][j]) break;
        }
        // cut[i, j]
        res[j] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        putchar(a[i]);
        if (i < n && res[i]) putchar(',');
    }
    putchar('\n');
    return 0;
}
