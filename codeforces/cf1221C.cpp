#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int q, c, m, x;
int a[N][N];

int main()
{
    cin >> q;
    for (int i = 0, res; i < q; ++i) {
        cin >> c >> m >> x;
        res = min(c, m);
        x += c+m-res-res;
        if (x >= res) {
            cout << res << endl;
            continue;
        } else {
            int d = res-x;
            d /= 3;
            res -= d;
            x += d*2;
            cout << min(res, x) << endl;
        }
    }
    return 0;
}
