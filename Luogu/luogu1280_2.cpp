#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n, k;
// dp[i] max of [i~n]
int dp[N];
vector<int> a[N];

int main()
{
    cin >> n >> k;
    for (int i = 1, p, t; i <= k; ++i) {
        cin >> p >> t;
        a[p].emplace_back(t);
    }
    for (int i = n; i; --i) {
        if (a[i].size()) {
            for (int j : a[i])
                dp[i] = max(dp[i], dp[min(i+j, n+1)]);
        } else {
            dp[i] = dp[i+1]+1;
        }
    }
    cout << dp[1] << endl;
    return 0;
}
