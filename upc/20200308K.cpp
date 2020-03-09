/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 20:25:01
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 20:59:02
 * @FilePath: \Code\upc\20200308K.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int P[] = {2,3,5,7,11,13,17,19,23};
const int Lim[] = {4,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1};

int c[N][N];

inline void init()
{
    c[0][0] = 1;
    for (int i = 1; i <= 10; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j <= i/2; ++j)
            c[i][j] = c[i][i-j] = c[i-1][j]+c[i-1][j-1];
    }
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << c[i][j] << " \n"[j==i];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, g, n, m;
    scanf("%d%d", &T, &g);
    init();
    while (T--) {
        scanf("%d %d", &n, &m);
        int res = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= i && j <= m; ++j) {
                if(c[i][j]%g == 0) ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}