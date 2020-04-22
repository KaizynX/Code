/*
 * @Author: Kaizyn
 * @Date: 2020-04-13 23:27:07
 * @LastEditTime: 2020-04-13 23:36:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int M = 2e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int a[N];
vector<int> dis;
vector<int> pos[M];

inline void solve()
{
    cin >> n;
    dis.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dis[i] = a[i];
    }
    sort(dis.begin(), dis.end());
    dis.erase(unique(dis.begin(), dis.end()), dis.end());
    m = dis.size();
    for (int i = 0; i < m; ++i) vector<int>().swap(pos[i]);
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(dis.begin(), dis.end(), a[i])-dis.begin();
        pos[a[i]].emplace_back(i);
    }
    int res = 0;
    for (int i = 0, l, r, now; i < m; ++i) {
        res = max(res, (int)pos[i].size());
        now = l = 0;
        r = pos[i].size()-1;
        while (l < r) {
            now += 2;
            for (int j = 0, ll, rr; j < m; ++j) {
                ll = upper_bound(pos[j].begin(), pos[j].end(), pos[i][l])-pos[j].begin();
                rr = lower_bound(pos[j].begin(), pos[j].end(), pos[i][r])-pos[j].begin();
                if (ll < rr) res = max(res, now+(rr-ll));
            }
            ++l; --r;
        }
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}