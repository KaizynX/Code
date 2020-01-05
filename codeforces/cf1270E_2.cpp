#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
int x[N], y[N];
int cnt[2][2];

inline int sum() {
    int res = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            res += cnt[i][j] != 0;
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        x[i] += 1e6;
        y[i] += 1e6;
        ++cnt[x[i]&1][y[i]&1];
    }
    while (sum() <= 1) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; ++i) {
            x[i] >>= 1;
            y[i] >>= 1;
            ++cnt[x[i]&1][y[i]&1];
        }
    }
    if (cnt[0][0]+cnt[1][1] && cnt[0][1]+cnt[1][0]) {
        cout << cnt[0][0]+cnt[1][1] << endl;
        for (int i = 1; i <= n; ++i) {
            if (x[i]%2 == y[i]%2)
                cout << i << " ";
        }
        cout << endl;
    } else {
        cout << cnt[0][0]+cnt[0][1] << endl;
        for (int i = 1; i <= n; ++i) {
            if (x[i]%2 == 0)
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
