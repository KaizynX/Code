#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+7;
const int MAXM = 1e6+7;
const int INF = 0x3f3f3f3f;

int n, m, k;
int e[MAXN][MAXN], d[MAXN][MAXN];
int a[MAXM], res[MAXM];

int main()
{
    cin >> n;
    memset(d, 0x3f, sizeof d);
    string str;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 1; j <= n; ++j) {
            e[i][j] = str[j-1]-'0';
            d[i][j] = e[i][j] ? 1 : INF;
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        d[i][i] = INF;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    res[++k] = a[1];
    for (int i = 3, last = 1; i <= m; ++i) {
        if (d[a[last]][a[i]] != i-last) {
            res[++k] = a[i-1];
            last = i-1;
        }
    }
    if (m > 1) res[++k] = a[m];
    cout << k << endl;
    for (int i = 1; i <= k; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
