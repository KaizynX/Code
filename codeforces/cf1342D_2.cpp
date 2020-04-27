/*
 * @Author: Kaizyn
 * @Date: 2020-04-26 22:34:31
 * @LastEditTime: 2020-04-26 23:52:53
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
int m[N], c[N], pre[N];
set<int> st;
vector<int> res[N];
vector<int> id[N];

inline void solve()
{
    // cin >> n >> k;
    // for (int i = 1; i <= n; ++i) cin >> m[i];
    // for (int i = 1; i <= k; ++i) cin >> c[i];
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", m+i);
    for (int i = 1; i <= k; ++i) scanf("%d", c+i);

    int cnt = 0;
    sort(m+1, m+n+1);
    reverse(m+1, m+n+1);
    for (int i = 1, last = 0; i <= k; ++i) {
        pre[i] = last;
        if (c[i]-c[i+1]) last = i;
    }
    for (int i = 1, j, p; i <= n; ++i) {
        auto it = st.lower_bound(m[i]);
        if (it == st.end()) {
            p = cnt++;
            j = k;
        }
        else {
            j = *it;
            p = id[j].back();
            id[j].pop_back();
            if (id[j].size() == 0) st.erase(j);
        }
        res[p].emplace_back(m[i]);
        // while (j && (int)res[p].size() >= c[j]) --j;
        if ((int)res[p].size() >= c[j]) j = pre[j];
        id[j].emplace_back(p);
        if (j && id[j].size() == 1) st.insert(j);
    }
    // cout << cnt << endl;
    printf("%d\n", cnt);
    for (int i = 0, p; i <= k; ++i) {
        while (id[i].size()) {
            p = id[i].back();
            id[i].pop_back();
            // cout << res[p].size() << " ";
            printf("%d ", (int)res[p].size());
            // for (int &j : res[p]) cout << j << " ";
            for (int &j : res[p]) printf("%d ", j);
            // cout << endl;
            putchar('\n');
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}