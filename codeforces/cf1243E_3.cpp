#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;
const int K = 15;

int k, dfn;
int n[K], p[K], c[K], a[K][N];
long long all;
long long sum[K];
vector<pair<int, int>> dp[1<<K];
map<long long, int> mp;

inline void check(int col, int val) 
{
    int i = col, v = val, state = 1<<col;
    long long target;
    vector<pair<int, int>> tmp;

    while (true) {
        target = v-sum[i];
        if (!mp.count(target)) return;
        v = static_cast<int>(target);
        tmp.emplace_back(v, i);
        i = mp[target];
        if (v == val) break;
        if (state&(1<<i)) return;
        state |= 1<<i;
    }
    dp[state] = tmp;
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n[i];
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j];
            sum[i] += a[i][j];
            mp.insert({a[i][j], i});
        }
        all += sum[i];
    }
    if (all%k) { cout << "No" << endl; return 0; }
    all /= k;
    for (int i = 0; i < k; ++i) sum[i] -= all;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            check(i, a[i][j]);
        }
    }
    for (int i = 1; i < (1<<k); ++i) {
        if (dp[i].size()) continue;
        for (int j = i; j; j = (j-1)&i) {
            if (dp[j].size() && dp[i-j].size()) {
                dp[i] = dp[i-j];
                dp[i].insert(dp[i].end(), dp[j].begin(), dp[j].end());
            }
        }
    }
    if (dp[(1<<k)-1].empty()) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for (auto pr : dp[(1<<k)-1]) {
            c[mp[pr.first]] = pr.first;
            p[mp[pr.first]] = pr.second;
        }
        for (int i = 0; i < k; ++i) {
            cout << c[i] << " " << p[i]+1 << endl;
        }
    }
    return 0;
}
