/*
 * @Author: Kaizyn
 * @Date: 2020-03-10 08:22:45
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-10 08:39:58
 * @FilePath: \Code\Luogu\luogu3389.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct GaussElimination
{
    double a[N][N];
    bool solve(const int &n) {
        for (int i = 1, j, k; i <= n; ++i) {
            k = i;
            for (j = i+1; j <= n; ++j)
                if (abs(a[j][i]) > abs(a[k][i])) k = j;
            if (abs(a[k][i]) < eps) return false;
            swap(a[k], a[i]);
            for (j = 1; j <= n; ++j) if (i != j) {
                double d = a[j][i]/a[i][i];
                for (k = i+1; k <= n+1; ++k)
                    a[j][k] -= d*a[i][k];
            }
        }
        for (int i = 1; i <= n; ++i) a[i][n+1] /= a[i][i];
        return true;
    }
};
GaussElimination GE;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n+1; ++j) {
            cin >> GE.a[i][j];
        }
    }
    if (!GE.solve(n)) return puts("No Solution")&0;
    for (int i = 1; i <= n; ++i) {
        printf("%.2f\n", GE.a[i][n+1]);
    }
    return 0;
}