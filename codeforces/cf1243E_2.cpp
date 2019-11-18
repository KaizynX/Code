#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;
const int K = 15;

int k, dfn;
int n[K], p[K], c[K], a[K][N], vis[K][N];
long long all;
long long sum[K];
vector<pair<int, int>> dp[1<<K];
map<int, int> before;
map<long long, pair<int, int>> mp;

inline bool solve(int i, int j, vector<pair<int, int>> &tmp)
{
    vis[i][j] = dfn;
    tmp.push_back({i, j});
    long long target = a[i][j]-sum[i];
    if (!mp.count(target)) return false;
    auto nex = mp[target];
    int x = nex.first, y = nex.second;
    if (vis[x][y]) return vis[x][y] == dfn;
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
            ++dfn;
            tmp.clear();
            if (!solve(i, j, tmp) || tmp.size() > k) continue;
            int now = 0;
            for (auto pr : tmp) {
                if (now&(1<<pr.first)) { now = 0; break; }
                now |= 1<<pr.first;
            }
            if (now) dp[now] = tmp;
        }
    }
    for (int i = 1; i < (1<<k); ++i) {
        if (dp[i].size()) {
            before.insert({i, 1});
            continue;
        }
        for (auto pr : before) {
            if ((i|pr.first) == i && before.count(i-pr.first)) {
                dp[i] = dp[pr.first];
                dp[i].insert(dp[i].end(), dp[i-pr.first].begin(), dp[i-pr.first].end());
                break;
            }
        }
        if (dp[i].size()) before.insert({i, 1});
    }
    if (dp[(1<<k)-1].empty()) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for (auto pr : dp[(1<<k)-1]) {
            c[pr.first] = a[pr.first][pr.second];
            p[mp[c[pr.first]-sum[pr.first]].first] = pr.first;
        }
        for (int i = 0; i < k; ++i) {
            cout << c[i] << " " << p[i]+1 << endl;
        }
    }
    return 0;
}
