/*
 * @Author: Kaizyn
 * @Date: 2020-04-13 22:32:43
 * @LastEditTime: 2020-04-13 23:16:26
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int d[] = {0,-1,0,1,0};

int n, m;
map<char, int> mp;
vector<string> col, dir;
vector<vector<int>> cir, vis;
vector<vector<pii>> dp;

pii dfs(const int &x, const int &y, const int &dep) {
    if (dp[x][y].first != -1) return dp[x][y];
    if (vis[x][y]) {
        int len = dep-vis[x][y];
        cir.emplace_back(vector<int>(len, 0));
        cir[cir.size()-1][len-1] |= (col[x][y]-'0')^1;
        return dp[x][y] = {cir.size()-1, len-1};
    }
    vis[x][y] = dep;
    pii pr = dfs(x+d[mp[dir[x][y]]], y+d[mp[dir[x][y]]+1], dep+1);
    int id = pr.first, len = cir[id].size();
    int pos = (pr.second-1+len)%len;
    cir[id][pos] |= (col[x][y]-'0')^1;
    return dp[x][y] = {id, pos};
}

inline void solve()
{
    cin >> n >> m;
    vector<vector<int>>(n, vector<int>(m, 0)).swap(vis);
    vector<vector<pii>>(n, vector<pii>(m, {-1, 0})).swap(dp);
    vector<vector<int>>().swap(cir);
    vector<string>(n).swap(col);
    vector<string>(n).swap(dir);
    for (int i = 0; i < n; ++i) cin >> col[i];
    for (int i = 0; i < n; ++i) cin >> dir[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) dfs(i, j, 1);
        }
    }
    int number = 0, black = 0;
    for (auto &vec : cir) {
        for (int &i : vec) black += i, ++number;
    }
    cout << number << " " << black << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    mp['L'] = 0;
    mp['U'] = 1;
    mp['R'] = 2;
    mp['D'] = 3;
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}