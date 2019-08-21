#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;

int n, m;
int a[kN][kN], sum[kN][kN], sort_a[kN], vis[kN], co[kN];
// sum[i][j] the number of group j in row i
// co[i] the row of group i
// vis[i] has group i been visited

inline void print()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int cur)
{
    for (int i = 1; i <= n; ++i) {
        if (!sum[cur][i] || vis[i]) continue;
        vis[i] = 1;
        if (!co[i] || check(co[i])) {
            co[i] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            int group = (a[i][j]-1)/m+1;
            ++sum[i][group];
        }
    }
    // phase 1
    for (int j = 1; j <= m; ++j) {
        memset(co, 0, sizeof co);
        for (int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            check(i);
        }
        /*
        for (int i = 1; i <= n; ++i) {
            --sum[i][co[i]];
            for (int k = j; k <= m; ++k) {
                int group = (a[i][k]-1)/m+1;
                if (group == co[i]) {
                    swap(a[i][j], a[i][k]);
                    break;
                }
            }
        }
        */
        for (int g = 1; g <= n; ++g) {
            int i = co[g];
            --sum[i][g];
            for (int k = j; k <= m; ++k) {
                int group = (a[i][k]-1)/m+1;
                if (group == g) {
                    swap(a[i][j], a[i][k]);
                    break;
                }
            }
        }
    }
    print();
    // phase 2
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            sort_a[i] = a[i][j];
        }
        sort(sort_a+1, sort_a+n+1);
        for (int i = 1; i <= n; ++i) {
            a[i][j] = sort_a[i];
        }
    }
    print();
    return 0;
}
