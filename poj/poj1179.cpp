#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const long long INF = 1e18;

int n;
int a[N];
char b[N];
long long minv[N][N], maxv[N][N];

inline void min_update(long long &x, const long long &y) { if (x > y) x = y; }
inline void max_update(long long &x, const long long &y) { if (x < y) x = y; }

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i] >> a[i];
        minv[i][i] = maxv[i][i] = a[i];
    }
    for (int i = n+1; i <= n*2; ++i) {
        a[i] = a[i-n];
        b[i] = b[i-n];
        minv[i][i] = maxv[i][i] = a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r; (r = l+len-1) <= n*2; ++l) {
            minv[l][r] = INF;
            maxv[l][r] = -INF;
            for (int k = l+1; k <= r; ++k) {
                if (b[k] == 't') {
                    min_update(minv[l][r], minv[l][k-1]+minv[k][r]);
                    min_update(minv[l][r], maxv[l][k-1]+minv[k][r]);
                    min_update(minv[l][r], minv[l][k-1]+maxv[k][r]);
                    min_update(minv[l][r], maxv[l][k-1]+maxv[k][r]);
                    max_update(maxv[l][r], minv[l][k-1]+minv[k][r]);
                    max_update(maxv[l][r], maxv[l][k-1]+minv[k][r]);
                    max_update(maxv[l][r], minv[l][k-1]+maxv[k][r]);
                    max_update(maxv[l][r], maxv[l][k-1]+maxv[k][r]);
                } else {
                    min_update(minv[l][r], minv[l][k-1]*minv[k][r]);
                    min_update(minv[l][r], maxv[l][k-1]*minv[k][r]);
                    min_update(minv[l][r], minv[l][k-1]*maxv[k][r]);
                    min_update(minv[l][r], maxv[l][k-1]*maxv[k][r]);
                    max_update(maxv[l][r], minv[l][k-1]*minv[k][r]);
                    max_update(maxv[l][r], maxv[l][k-1]*minv[k][r]);
                    max_update(maxv[l][r], minv[l][k-1]*maxv[k][r]);
                    max_update(maxv[l][r], maxv[l][k-1]*maxv[k][r]);
                }
            }
#ifdef DEBUG
            printf("[%d, %d] %lld %lld\n", l, r, minv[l][r], maxv[l][r]);
#endif
        }
    }
    long long res = -INF;
    for (int i = 1; i+n-1 <= 2*n; ++i)
        res = max(res, maxv[i][i+n-1]);
    cout << res << endl;
    for (int i = 1; i <= n; ++i) {
        if (maxv[i][i+n-1] == res)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
