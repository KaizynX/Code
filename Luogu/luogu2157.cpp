#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;
const int B = 15;
const int INF = 1e9;

int testcase, n;
int t[N], b[N], lef[N], rig[N];
vector<int> v[N];
map<int, int> mp[N];
typedef pair<int, int> pii;
map<pii, int> dp[2];

// change a state of x'th to the state of y'th
inline int change(int s, int x, int y) {
    int res = 0;
    for (int i = 0; i < (int)v[x].size(); ++i) if ((s>>i)&1)
        if (mp[y].count(v[x][i])) res += 1<<mp[y][v[x][i]];
    return res;
}

// check if the state of x'th is ok for k
inline bool check(int s, int x, int k) {
    int cnt = 0;
    for (int i = 0; i < (int)v[x].size(); ++i) if ((s>>i)&1) {
        if (v[x][i] == k) return false;
        if (v[x][i] > k) ++cnt;
    }
    return cnt <= b[k];
}

int main()
{
    cin >> testcase;
    while (testcase--) {
        cin >> n;
        dp[0].clear();
        dp[1].clear();
        for (int i = 1; i <= n+1; ++i) {
            lef[i] = i;
            v[i].clear();
            mp[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            cin >> t[i] >> b[i];
            rig[i] = min(n, i+b[i]);
            lef[min(n, i+b[i])] = min(lef[min(n, i+b[i])], i);
        }
        for (int i = n; i; --i) {
            lef[i] = min(lef[i], lef[i+1]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = lef[i]; j <= rig[i]; ++j) {
                mp[j][i] = v[j].size();
                v[j].emplace_back(i);
            }
        }
        dp[0].insert({{0, 0}, 0});
        for (int i = 1; i <= n; ++i) {
            dp[i&1].clear();
            for (auto p : dp[(i-1)&1]) {
                pii a = p.first;
                int s = change(a.first, i-1, i);
                for (int j = 0; j < (int)v[i].size(); ++j) if (check(s, i, v[i][j])) {
                    pii now = {s|(1<<j), j};
                    int val = i == 1 ? 0 : p.second+(t[v[i-1][a.second]]^t[v[i][j]]);
                    if (dp[i&1].count(now)) dp[i&1][now] = min(dp[i&1][now], val);
                    else dp[i&1].insert({now, val});
                }
            }
        }
        int tmp = (1<<v[n].size())-1, res = INF;
        for (int i = 0; i < (int)v[n].size(); ++i) if (dp[n&1].count({tmp, i}))
            res = min(res, dp[n&1][{tmp, i}]);
        cout << res << endl;
    }
    return 0;
}
