#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n, k, x, y, z, u, v;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> k;
        int zys = 0, zyn = 0, jds = 0, jdn = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x >> y >> z;
            if (z) {
                zys += x;
                ++zyn;
            }
            jds += y*(x >= 95 ? 500 : (x-45)*10);
            jdn += y;
        }
        cin >> u >> v;
        double res = 0.2*u+v;
        if (jdn) res += 1.0*jds/jdn;
        if (zyn) res += 0.7*zys/zyn;
        // cout << res << endl;
        cout << (res >= k ? "Yes" : "No") << endl;
    }
    return 0;
}
