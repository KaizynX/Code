#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n, d, a;
int x[N], h[N], del[N*3], hhh[N*3];
vector<int> des;

inline void solve()
{
    cin >> n >> d >> a;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> h[i];

    sort(x+1, x+n+1);
    des.resize(n*3);
    for (int i = 1; i <= n; ++i) {
        des[i*3-3] = x[i]-d;
        des[i*3-2] = x[i];
        des[i*3-1] = x[i]+d;
    }
    // des.emplace_back(x[n]+d+d);
    sort(des.begin(), des.end());
    des.erase(unique(des.begin(), des.end()), des.end());
    #ifdef DEBUG
    for (int i : des) cout << i << " ";
    cout << endl;
    #endif

    for (int i = 1; i <= n; ++i) {
        x[i] = lower_bound(des.begin(), des.end(), x[i])-des.begin();
        hhh[x[i]] += h[i];
    }
    long long res = 0;
    for (int i = 1, j = 0, now = 0, t, k; i <= n; ++i) {
        while (j <= x[i]) now -= del[j++]*a;
        if (now >= hhh[i]) continue;
        t = (hhh[i]-now)/a+((hhh[i]-now)%a != 0);
        res += t;
        now += t*a;
        // operator at x[i]+d
        int p = upper_bound(des.begin(), des.end(), des[x[i]]+d+d)-des.begin();
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