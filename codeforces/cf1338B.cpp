/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 22:02:19
 * @LastEditTime: 2020-04-13 08:48:58
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

int n, minans = 1, maxans;
vector<int> e[N];

// 2 - even, 1 - odd, 3 - odd+even
int dfs(const int &u, const int &fa) {
    int son = 0;
    for (int &v : e[u]) if (v != fa) {
        int tmp = dfs(v, u);
        son |= tmp;
    }
    if (son == 3) minans = 3;
    // len+1,turn odd to even, even to odd
    if (son) return son^3;
    else return 2; // zero
}

int dfs2(const int &u, const int &fa) {
    int flag = 0, cur = 0;
    for (int &v : e[u]) if (v != fa) {
        int tmp = dfs2(v, u);
        if (tmp == 1) {
            if (flag) --maxans;
            else flag = 1;
        }
        cur = max(tmp, cur);
    }
    return cur+1;
}

inline void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    maxans = n-1;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() > 1) {
            dfs(i, 0);
            dfs2(i, 0);
            break;
        }
    }
    cout << minans << " " << maxans << endl;
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