#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int T, n;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res = max(res, min(a[i], i));
        }
        cout << res << endl;
    }
    return 0;
}

