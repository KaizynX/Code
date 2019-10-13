#include <bits/stdc++.h>

using namespace std;

const int N = 12;
const int T = 10;

int n[N+3], v[N+3], a[N+3][N+3];

inline void init()
{
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            a[i][j] =  (i%3 == 1 || j%3 == 1 || i == j ? 1 : 0);
        if (i%3 == 2) {
            a[i][i+1] = 1;
            a[i][(i+6)%N] = 1;
            a[i][(i-3+N)%N+1] = 1;
        } else if (i%3 == 0) {
            a[i][i-1] = 1;
            a[i][(i+3)%N-1] = 1;
            a[i][(i+6)%N] = 1;
        }
    }
}

int main()
{
    init();
    for (int i = 1; i <= N; ++i) cin >> n[i];
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        if (i%3 == 1) n[i] = max(0, n[i]-v[i]*T);
    }
    for (int t = 0, maxi; t < T; ++t) {
        maxi = 2;
        for (int i = 3; i <= N; ++i)
            if (i%3 != 1 && n[i] > n[maxi]) maxi = i;
        if (n[maxi] == 0) break;
        for (int i = 1; i <= N; ++i)
            if (i%3 != 1 && a[maxi][i]) n[i] = max(0, n[i]-v[i]);
    }
    int res = 0;
    for (int i = 1; i <= N; ++i)
        res = max(res, n[i]);
    cout << res << endl;
    return 0;
}
