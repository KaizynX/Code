#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;
const int MOD = 1e9+7;
typedef pair<int, int> pii;

int n, tp;
int a[N];
long long pre[N], bac[N];
pii stk[N];

inline void update(long long sum[])
{
    tp = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1];
        while (tp && stk[tp].first >= a[i]) {
            sum[i] -= 1ll*stk[tp].first*(stk[tp].second-stk[tp-1].second);
            --tp;
        }
        sum[i] += 1ll*a[i]*(i-stk[tp].second);
        stk[++tp] = {a[i], i};
    }
}

inline long long calc(const int &i)
{
    return pre[i]+bac[n-i+1]-a[i];
}

inline void print(const int &mid)
{
    static int res[N];
    tp = 0;
    for (int i = 1; i <= mid; ++i) {
        while (tp && stk[tp].first >= a[i]) --tp;
        stk[++tp] = {a[i], i};
    }
    for (int i = 1; i <= tp; ++i)
        for (int j = stk[i-1].second+1; j <= stk[i].second; ++j)
            res[j] = stk[i].first;

    stk[tp = 0] = {0, n+1};
    for (int i = n; i >= mid; --i) {
        while (tp && stk[tp].first >= a[i]) --tp;
        stk[++tp] = {a[i], i};
    }
    for (int i = 1; i <= tp; ++i)
        for (int j = stk[i-1].second-1; j >= stk[i].second; --j)
            res[j] = stk[i].first;

    for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    update(pre);
    reverse(a+1, a+n+1);
    update(bac);
    reverse(a+1, a+n+1);
    int res = 1;
    for (int i = 2; i <= n; ++i)
        if (calc(i) > calc(res))
            res = i;
    print(res);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}