#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int T, n, p, k;
int a[N], dp[N];

inline bool check(int mid)
{
    int need = 0, i = mid;
    for (; i >= k; i -= k) need += a[i];
    while (i) need += a[i--];
    return need <= p;
    /*
    for (int i = mid; i > 0; i -= (i >= k ? k : 1)) {
        if (rest < a[i]) return false;
        rest -= a[i];
    }
    return true;
    */
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> p >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            dp[i] = 0;
        }
        sort(a+1, a+n+1);
        int res = 0;
        for (int i = 1; i < k; ++i) {
            dp[i] = dp[i-1]+a[i];
            if (dp[i] <= p) res = i;
        }
        for (int i = k; i <= n; ++i) {
            dp[i] = dp[i-k]+a[i];
            if (dp[i] <= p) res = i;
        }
        cout << res << endl;
        /*
        int l = 0, r = n;
        while (l < r) {
            int mid = (l+r+1)>>1;
            if (check(mid)) l = mid;
            else r = mid-1;
        }
        cout << l << endl;
        */
    }
    return 0;
}

