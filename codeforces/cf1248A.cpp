#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int t, n, m;
int p[N], q[N];

int main()
{
    cin >> t;
    while (t--) {
        int cntn = 0, cntm = 0;
        cin >> n;
        for (int i = 1, p; i <= n; ++i) {
            cin >> p;
            cntn += p&1;
        }
        cin >> m;
        for (int i = 1, q; i <= m; ++i) {
            cin >> q;
            cntm += q&1;
        }
        long long res = 1ll*cntn*cntm+1ll*(n-cntn)*(m-cntm);
        cout << res << endl;
    }
    return 0;
}
