#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int INF = 1e8;

int n, res = INF;
long long a[kN];
int f[200][200];
vector<long long> v[80];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!a[i]) {
            --i, --n;
            continue;
        }
        for (int j = 0; j < 64; ++j) {
            if (a[i]&(1<<j)) v[j].push_back(a[i]);
        }
    }
    for (int i = 0; i < 64; ++i) {
        if (v[i].size() >= 3) {
            cout << 3 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j || (a[i]&a[j]) == 0) {
                f[i][j] = INF;
            } else {
                f[i][j] = 1;
            }
            printf("%9d ", f[i][j]);
        }
        cout << endl;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int now = f[i][k]+f[k][j];
                if (i == j && now <= 2) continue;
                f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%9d ", f[i][j]);
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        res = min(res, f[i][i]);
    }
    cout << (res == INF ? -1 : res) << endl;
    return 0;
}
