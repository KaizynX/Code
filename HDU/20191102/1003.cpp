#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;

int t, n;
long long a[N], dp[N];

int main()
{
#ifdef DEBUG
    cout << "&a[N-1]:" << (int*)&a[N-1] << endl;
    cout << "&a[N]:" << (int*)&a[N] << endl;
    cout << "&dp[-1]:" << (int*)&dp[-1] << endl;
    cout << "&dp[0]:" << (int*)&dp[0] << endl;
    cout << "dp[-1]:" << dp[-1] << endl;
    cout << "&n:" << (int*)&n << endl;
    cout << "&t:" << (int*)&t << endl;
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof a);
        memset(dp, 0, sizeof dp);
        int mx = 0;
        for (int i = 1, tmp; i <= n; ++i) {
            cin >> tmp;
            mx = max(mx, tmp);
            a[tmp] += tmp;
        }
        for (int i = 1; i <= mx; ++i) {
            dp[i] = max(dp[i-1], a[i]+dp[i-2]);
        }
        cout << dp[mx] << endl;
    }
    return 0;
}
