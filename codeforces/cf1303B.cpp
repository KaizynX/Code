#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n, g, b, m;
long long res;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> g >> b;
        m = (n+1)/2;
        if (m%g) res = 1ll*m/g*(g+b)+m%g;
        else res = 1ll*m/g*(g+b)-b;
        cout << max(res, 1ll*n) << endl;
    }
    return 0;
}
