#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e3+7;
const double err = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;
typedef pair<int, int> pii;

int n, m;
int a[N], vis[N], appear[N], pre[N], bac[N];
// v[i] the h of all eat (f[] == i)
int res_num;
long long res_cnt;
vector<int> v[N], t[N];
vector<pii> s;

inline void update(const int &num, const long long &cnt) {
    if (num > res_num) {
        res_num = num;
        res_cnt = cnt;
    } else if (num == res_num) {
        res_cnt = (res_cnt+cnt)%MOD;
    }
}

inline void calc(const int &mid) {
    int num = 0;
    long long cnt = 1;
    for (int i = 1; i <= n; ++i) vector<int>().swap(t[i]);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < mid; ++i) {
        pii &p = s[i];
        if (vis[p.first]) continue;
        vis[p.first] = 1;
        t[p.first].emplace_back(p.second);
    }
    memset(vis, 0, sizeof vis);
    for (int i = (int)s.size()-1; i > mid; --i) {
        pii &p = s[i];
        if (vis[p.first]) continue;
        vis[p.first] = 1;
        t[p.first].emplace_back(p.second);
    }
    for (int i = 1; i <= n; ++i) {
        if (!t[i].size()) continue;
        if (t[i].size() == 1) {
            int p = upper_bound(v[i].begin(), v[i].end(), t[i][0])-v[i].begin();
            if (!p) continue;
            ++num;
            cnt = cnt*p%MOD;
        } else if (t[i].size() == 2) {
            int p0 = upper_bound(v[i].begin(), v[i].end(), t[i][0])-v[i].begin(),
                p1 = upper_bound(v[i].begin(), v[i].end(), t[i][1])-v[i].begin();
            if (!p0 && !p1) continue;
            if (p0 > p1) swap(p0, p1);
            if (!p0) {
                ++num;
                cnt = cnt*p1%MOD;
            } else {
                num += 2;
                cnt = cnt*p0*(p1-1)%MOD;
            }
        }
    }
    if (mid < 0 || mid >= (int)s.size()) { update(num, cnt); return; }
    int tmp = 0, cur = s[mid].first;
    for (int i = 0; i < (int)v[cur].size(); ++i) {
        // if (v[cur][i] > s[mid].second) break;
        int p = upper_bound(v[cur].begin(), v[cur].end(), s[mid].second-v[cur][i])-v[cur].begin();
        if (!p) break;
        tmp += p-(p > i);
    }
    if (!tmp) return;
    num += 2;
    cnt = cnt*tmp%MOD;
    update(num, cnt);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> a[1];
    int last = a[1], num = 1;
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == last) ++num;
        else {
            ++appear[last];
            s.emplace_back(last, num);
            last = a[i];
            num = 1;
        }
    }
    ++appear[last];
    s.emplace_back(last, num);
    for (int i = 1, f, h; i <= m; ++i) {
        cin >> f >> h;
        v[f].emplace_back(h);
    }
    for (int i = 1; i <= n; ++i)
        sort(v[i].begin(), v[i].end());

    calc(-1);
    calc(s.size());
    for (int mid = 0; mid < (int)s.size(); ++mid) {
        if (appear[s[mid].first] > 1) continue;
        calc(mid);
    }
    if (!res_num) res_cnt = 1;
    cout << res_num << " " << res_cnt << endl;
    return 0;
}
