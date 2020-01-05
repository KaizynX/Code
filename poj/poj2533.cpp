#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3+7;
const int INF = 0x7f7f7f7f;

int n, res = 0;
int a[N], dp[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
