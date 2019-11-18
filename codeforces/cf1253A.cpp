#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int t, n;
int a[N], b[N], c[N];

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 1; i <= n; ++i) c[i] = b[i]-a[i];
        int flag = 1;
        int l = 1, r = n;
        while (l <= r && c[l] == 0) ++l;
        while (l <= r && c[r] == 0) --r;
        for (int i = l; i <= r; ++i) {
            if (c[i] != c[l] || c[i] < 0) {
                flag = 0;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
