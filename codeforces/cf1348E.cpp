/*
 * @Author: Kaizyn
 * @Date: 2020-05-01 23:37:31
 * @LastEditTime: 2020-05-02 00:15:25
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k;
int a[N], b[N];

inline void solve()
{
    cin >> n >> k;
    long long cnt = 0, sum = 0, res = 0;
    int mina = 0, maxa = 0, minb = 0, maxb = 0, rest = 0;
    bool flag = false;
    for (int i = 1, la, lb, ra, rb, mod; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] >= k && b[i] >= k) flag = true;
        sum += a[i]+b[i];
        cnt += (a[i]+b[i])/k;
        mod = (a[i]+b[i])%k;
        rest += mod;
        ra = min(a[i], mod);
        rb = min(b[i], mod);
        la = min(a[i], mod-rb);
        lb = min(b[i], mod-ra);
        mina += la; maxa += ra;
        minb += lb; maxb += rb;
    }
    if (flag) return void(cout << sum/k << endl);
    for (int aa = mina, bb; aa <= maxa; ++aa) {
        bb = rest-aa;
        if (bb < minb || bb > maxb) continue;
        res = max(res, cnt+aa/k+bb/k);
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