#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;
const int K = 20;

int k;
int n[K], p[K], c[K], a[K][N], vis[K][N];
long long all;
long long sum[K];
// dp[i] 满足i(二进制)的坐标们
vector<pair<int, int>> dp[1<<15];
// 记录某个值的坐标
map<long long, pair<int, int>> mp;

inline bool solve(int i, int j, vector<pair<int, int>> &tmp)
{
    vis[i][j] = 1;
    tmp.push_back({i, j});
    long long target = a[i][j]-sum[i];
    if (!mp.count(target)) return false;
    auto nex = mp[target];
    int x = nex.first, y = nex.second;
    if (vis[x][y]) return true;
    return solve(x, y, tmp);
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n[i];
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j];
            sum[i] += a[i][j];
            mp.insert({a[i][j], {i, j}});
        }
        all += sum[i];
    }
    if (all%k) { cout << "No" << endl; return 0; }
    all /= k;
    for (int i = 0; i < k; ++i) sum[i] -= all;

    vector<pair<int, int>> tmp;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            tmp.clear();
            if (!solve(i, j, tmp)) continue;
            int now = 0;
            for (auto pr : tmp) {
                if (now&(1<<pr.first)) { now = 0; break; }
                now |= 1<<pr.first;
            }
            if (now) dp[now] = tmp;
        }
    }
    for (int i = 1; i < (1<<k); ++i) {
        if (dp[i].empty()) continue;
        if (i == (1<<k)-1 || dp[(1<<k)-1-i].size()) {
            cout << "Yes" << endl;
            for (auto pr : dp[i]) {
                c[pr.first] = a[pr.first][pr.second];
                p[mp[c[pr.first]-sum[pr.first]].first] = pr.first;
            }
            for (auto pr : dp[(1<<k)-i-1]) {
                c[pr.first] = a[pr.first][pr.second];
                p[mp[c[pr.first]-sum[pr.first]].first] = pr.first;
            }
            for (int i = 0; i < k; ++i) {
                cout << c[i] << " " << p[i]+1 << endl;
            }
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
