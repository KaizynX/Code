#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a, b, c, d, e, f;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c >> d >> e >> f;
    // (a, d) (b, c, d)
    int res = 0;
    for (int i = 0, j; i <= d; ++i) {
        j = d-i;
        if (a < i) break;
        if (b < j || c < j) continue;
        res = max(res, e*i+f*j);
    }
    cout << res << endl;
    // cout << max(min(a, d)*e, min(d, min(b, c))*f) << endl;
    return 0;
}
