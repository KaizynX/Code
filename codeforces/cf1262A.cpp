#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int INF = 1e9;

int t, n;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int ll = INF, rr = 0;
        for (int i = 1, l, r; i <= n; ++i) {
            cin >> l >> r;
            ll = min(ll, r);
            rr = max(rr, l);
        }
        cout << max(0, rr-ll) << endl;
    }
    return 0;
}
