#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int q, n, r;
int a[N];

int main()
{
    cin >> q;
    while (q--) {
        cin >> n >> r;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        n = unique(a+1, a+n+1)-a-1;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        int res = n;
        for (int i = n-1, t; i; --i) {
            t = n-i;
            if (a[i]-t*r <= 0) {
                res = t;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
