/*
 * @Author: Kaizyn
 * @Date: 2020-04-26 16:14:42
 * @LastEditTime: 2020-04-26 17:00:34
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;


inline void solve()
{
    int n;
    vector<set<int>> a;
    cin >> n;
    a.resize(n-1);
    for (int i = 0, k; i < n-1; ++i) {
        cin >> k;
        for (int j = 0, x; j < k; ++j) {
            cin >> x;
            a[i].insert(x);
        }
    }
    for (int fst = 1; fst <= n; ++fst) {
        vector<int> res(1, fst);
        vector<set<int>> b = a;
        for (auto &s : b) if (s.count(fst)) s.erase(fst);
        int flag = 1;
        for (int i = 1; i < n; ++i) {
            int cnt1 = 0, nxt;
            for (auto &s : b) if (s.size() == 1) {
                ++cnt1;
                nxt = *s.begin();
            }
            if (cnt1 != 1) { flag = 0; break; }
            res.emplace_back(nxt);
            for (auto &s : b) if (s.count(nxt) == 1) {
                s.erase(nxt);
            }
        }
        if (!flag) continue;
        set<set<int>> c(a.begin(), a.end());
        for (int r = 1; r < n; ++r) {
            set<int> cur;
            for (int l = r; l >= 0; --l) {
                cur.insert(res[l]);
                if (c.count(cur)) {
                    c.erase(cur);
                    break;
                }
            }
        }
        if (c.size()) continue;
        for (int &i : res) cout << i << " ";
        cout << endl;
        return;
    }
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