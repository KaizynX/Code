/*
 * @Author: Kaizyn
 * @Date: 2020-03-30 13:14:42
 * @LastEditTime: 2020-03-30 13:31:31
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k;
int a[N];
map<int, int> mp;
long long sum[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1]+a[i];
        if (++mp[a[i]] >= k) return (cout << 0 << endl), 0;
    }
    int p = k;
    while (p+1 <= n && a[p+1] == a[k]) ++p;
    long long res = 1ll*k*a[k]-sum[k]-(p-k);
    p = n-k+1;
    while (p-1 >= 1 && a[p-1] == a[n-k+1]) --p;
    res = min(res, sum[n]-sum[n-k]-1ll*k*a[n-k+1]-(n-k+1-p));
    for (int i = 1; i <= n; ++i) {
        res = min(res, 1ll*i*a[i]-sum[i]+sum[n]-sum[i]-1ll*(n-i)*a[i]-(n-k));
    }
    cout << res << endl;
    return 0;
}