#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int maxd = 0, maxdis = -INF;
        for (int i = 0, d, h; i < n; ++i) {
            cin >> d >> h;
            maxd = max(maxd, d);
            maxdis = max(maxdis, d-h);
        }
        if (x <= maxd) cout << 1 << endl;
        else if (maxdis <= 0) cout << -1 << endl;
        else cout << (x-maxd)/maxdis+((x-maxd)%maxdis ? 2 : 1) << endl;
        // else cout << (x-maxd+maxdis-1)/maxdis+1 << endl;
    }
    return 0;
}
