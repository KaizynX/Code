#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int k, n, res;
int a[N];

int main()
{
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        res = 0;
        for (int i = 1; i <= n; ++i) {
            res = max(res, min(a[i], i));
        }
        cout << res << endl;
    }
    return 0;
}
