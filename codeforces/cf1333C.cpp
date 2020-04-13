/*
 * @Author: Kaizyn
 * @Date: 2020-04-08 22:32:11
 * @LastEditTime: 2020-04-08 23:20:01
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

int n;
int a[N];
long long sum[N];
map<long long, int> mp;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    mp.clear();
    mp[0] = 0;
    long long res = 0;
    for (int i = 1, last = 0; i <= n; ++i) {
        sum[i] = sum[i-1]+a[i];
        if (mp.count(sum[i])) {
            last = max(last, mp[sum[i]]+1);
        }
        res += i-last;
        mp[sum[i]] = i;
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}