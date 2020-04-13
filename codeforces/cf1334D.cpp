/*
 * @Author: Kaizyn
 * @Date: 2020-04-10 22:25:36
 * @LastEditTime: 2020-04-11 00:07:45
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
long long l, r;

inline long long calc(const int &x)
{
    if (x == n) return n*(n-1ll)+1;
    return (n-1ll+(n-x))*x;
}

inline void solve()
{
    // cin >> n >> l >> r;
    scanf("%d %lld %lld", &n, &l, &r);
    if (l > r) swap(l, r);
    long long sum = 0, k = 1, now;
    int ll = 1, rr = n;
    while (ll < rr) {
        int mid = (ll+rr+1)/2;
        if (calc(mid) < l) ll = mid;
        else rr = mid-1;
        // if (calc(mid) >= l) rr = mid;
        // else ll = mid+1;
    }
    k = ll;
    sum = calc(ll-1);
    #ifdef DEBUG
    cout << k << " " << sum << endl;
    #endif
    for (; k < n && sum <= r; ++k, sum += now) {
        now = (n-k)*2;
        if (sum+now < l) continue;
        for (long long i = max(l, sum+1); i <= r && i <= sum+now; ++i) {
            if ((i-sum)&1) {
                // cout << k << " ";
                printf("%lld ", k);
            } else {
                // cout << (i-sum)/2+k << " ";
                printf("%lld ", (i-sum)/2+k);
            }
        }
        if (sum+now >= r) return void(putchar('\n'));
    }
    // if (sum < r) cout << 1;
    // cout << endl;
    if (r == n*(n-1ll)+1) putchar('1');
    putchar('\n');
}

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    scanf("%d", &testcase);
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}