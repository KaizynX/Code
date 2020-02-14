#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e2+7;

int n;
int a[N], b[5], cnt[N][N];
// cnt[i][j] the number of j in [i+1, n]

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j < i; ++j)
            ++cnt[j][a[i]];
    }
    for (int i = 1; i <= 4; ++i)
        cin >> b[i];

    long long res = 0;
    for (int i1 = 1; i1 < n; ++i1)
    for (int i2 = i1+1; i2 < n; ++i2)
    for (int i3 = i2+1; i3 < n; ++i3) {
        if ((b[1] == b[2] && a[i1] != a[i2]) ||
            (b[1] != b[2] && a[i1] == a[i2]) ||
            (b[1] == b[3] && a[i1] != a[i3]) ||
            (b[1] != b[3] && a[i1] == a[i3]) ||
            (b[2] == b[3] && a[i2] != a[i3]) ||
            (b[2] != b[3] && a[i2] == a[i3]))
            continue;
        if (b[4] == b[1]) {
            res += cnt[i3][a[i1]];
        } else if (b[4] == b[2]) {
            res += cnt[i3][a[i2]];
        } else if (b[4] == b[3]) {
            res += cnt[i3][a[i3]];
        } else {
            int del = cnt[i3][a[i1]];
            if (b[2] != b[1]) del += cnt[i3][a[i2]];
            if (b[3] != b[1] && b[3] != b[2]) del += cnt[i3][a[i3]];
            res += n-i3-del;
        }
#ifdef DEBUG
        printf("%d %d %d %lld\n", i1, i2, i3, res);
#endif
    }
    cout << res << endl;
    return 0;
}
