#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const long long INF = 1e18;

int n;
long long a[N], dp[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            dp[i] = 0;
        }
        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] <= a[j]) continue;
                dp[i] = max(dp[i], dp[j]+a[i]);
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}
