#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;
const double err = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;
typedef pair<int, int> pii;

int n, m, ans;
int s[N], f[N], h[N], vis[N];
long long res[N];
// v[i] the h of all eat (f[] == i)
vector<int> v[N], t[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= m; ++i) {
        cin >> f[i] >> h[i];
        v[f[i]].emplace_back(h[i]);
    }
    for (int i = 1; i <= n; ++i)
        sort(v[i].begin(), v[i].end());
    for (int i = 1; i < n; ++i) {
        // [1, i] [i+1, n]
        for (int j = 1; j <= n; ++j)
            vector<int>().swap(t[j]);
        memset(vis, 0, sizeof vis);
        int last = s[1], num = 1;
        for (int j = 2; j <= i; ++j) {
            if (s[j] == last) ++num;
            else {
                if (!vis[last]) {
                    vis[last] = 1;
                    t[last].emplace_back(num);
                }
                last = s[j];
                num = 1;
            }
        }
        if (!vis[last]) t[last].emplace_back(num);

        memset(vis, 0, sizeof vis);
        last = s[n]; num = 1;
        for (int j = n-1; j > i; --j) {
            if (s[j] == last) ++num;
            else {
                if (!vis[last]) {
                    vis[last] = 1;
                    t[last].emplace_back(num);
                }
                last = s[j];
                num = 1;
            }
        }
        if (!vis[last]) t[last].emplace_back(num);

        num = 0;
        long long cnt = 1;
        for (int i = 1; i <= n; ++i) {
            num += t[i].size();
            if (!t[i].size()) continue;
            else if (t[i].size() == 1) {
                int p = upper_bound(v[i].begin(), v[i].end(), t[i][0])-v[i].begin();
                if (!p) continue;
                cnt = cnt*p%MOD;
            } else {
                int p1 = upper_bound(v[i].begin(), v[i].end(), t[i][0])-v[i].begin(),
                    p2 = upper_bound(v[i].begin(), v[i].end(), t[i][1])-v[i].begin();
                if (p1 > p2) swap(p1, p2);
                if (p2 < 2) continue;
                if (!p1) p1 = 1;
                if (!p2) p2 = 1;
                cnt = cnt*p1*(p2-1)%MOD;
            }
        }
        ans = max(ans, num);
        res[num] = (res[num]+cnt)%MOD;
    }
    cout << ans << " " << res[ans] << endl;
    return 0;
}
