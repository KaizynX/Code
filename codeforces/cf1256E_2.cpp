#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int INF = 0x3f3f3f3f;

int n;
int t[N], dp[N], last[N];

struct Node
{
    int v, id;
    friend bool operator < (const Node &x, const Node &y) {
        return x.v < y.v;
    }
} a[N];

int main()
{
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = max(0, i-5); j <= i-3; ++j) {
            // dp[i] = min(dp[i], dp[j]+a[i].v-a[j+1].v);
            if (dp[i] > dp[j]+a[i].v-a[j+1].v) {
                dp[i] = dp[j]+a[i].v-a[j+1].v;
                last[i] = j;
            }
        }
    }
    int tot = 0;
    for (int i = n; i; i = last[i]) {
        ++tot;
        for (int k = i; k > last[i]; --k) {
            t[a[k].id] = tot;
        }
    }

    cout << dp[n] << " " << tot << endl;
    for (int i = 1; i <= n; ++i) {
        cout << (t[i] ? t[i] : 1) << " \n"[i==n];
    }
    return 0;
}
