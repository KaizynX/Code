#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n, d, a;
int x[N], h[N], del[N], hhh[N];
vector<int> des;

inline void solve()
{
    cin >> n >> d >> a;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> h[i];

    des.resize(n);
    for (int i = 1; i <= n; ++i)
        des[i-1] = x[i];
    sort(des.begin(), des.end());
    des.erase(unique(des.begin(), des.end()), des.end());
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(des.begin(), des.end(), x[i])-des.begin();
        hhh[p] += h[i];
    }
    long long res = 0;
    int i = 0, t = 0, p;
    while (i < (int)des.size() && des[i]-d >= des[0]) t = max(t, hhh[i++]);
    t = t/a+(t%a != 0);
    res += t;
    p = upper_bound(des.begin(), des.end(), des[i-1]+d)-des.begin();
    del[p] += t;
    for (int now = t*a; i < (int)des.size(); ++i) {
        now -= del[i]*a;
        if (now >= hhh[i]) continue;
        t = (hhh[i]-now)/a+((hhh[i]-now)%a != 0);
        res += t;
        now += t*a;
        p = upper_bound(des.begin(), des.end(), des[i]+d)-des.begin();
        del[p] += t;
    }
    cout << res << endl;
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