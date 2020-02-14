#include <bits/stdc++.h>

using namespace std;

const int N = 4e3+7;
const int INF = 2e9;

int T, n, m, k;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        if (k >= m) k = m-1;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int res = 0;
        for (int l = 0, r, tmp; l <= k; ++l) {
            r = k-l;
            tmp = INF;
            for (int i = 0, j; i <= m-1-k; ++i) {
                j = m-1-k-i;
                tmp = min(tmp, max(a[1+l+i], a[n-r-j]));
            }
            res = max(tmp, res);
        }
        cout << res << endl;
    }
    return 0;
}
