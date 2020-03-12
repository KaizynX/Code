/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 18:57:54
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 14:24:42
 * @FilePath: \Code\atcoder\abc157F.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 65;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-7;
typedef pair<int, int> pii;

int n, k;
int x[N], y[N], c[N];
int g[N][N];
double d[N][N], r[N];

struct MaxClique
{
    vector<int> res, tmp, cnt;
    bool dfs(int p) {
        for (int i = p+1, flag; i <= n; ++i) {
            if (cnt[i]+tmp.size() <= res.size()) return false;
            if (!g[p][i]) continue;
            flag = 1;
            for (int j : tmp)
                if (!g[i][j]) flag = 0;
            if (!flag) continue;
            tmp.push_back(i);
            if (dfs(i)) return true;
            tmp.pop_back();
        }
        if (tmp.size() > res.size()) {
            res = tmp;
            return true;
        }
        return false;
    }
    int solve() {
        vector<int>(n+1, 0).swap(cnt);
        vector<int>().swap(res);
        for (int i = n; i; --i) {
            vector<int>(1, i).swap(tmp);
            dfs(i);
            cnt[i] = res.size();
        }
        return res.size();
    }
} MC;

inline bool check(const double &mid)
{
    for (int i = 1; i <= n; ++i) {
        r[i] = mid/c[i];
        for (int j = 1; j < i; ++j) {
            g[i][j] = g[j][i] = (r[i]+r[j] >= d[i][j]);
        }
    }
    return MC.solve() >= k;
}

inline void solve()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", x+i, y+i, c+i);
        for (int j = 1; j < i; ++j) {
            d[i][j] = d[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    double l = .0, r = 2e5, mid;
    while (r-l > eps) {
        mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.7f\n", l);
}

int main()
{
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}