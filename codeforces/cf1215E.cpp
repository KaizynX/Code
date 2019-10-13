#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5+7;
const int MAXC = 25;

int n;
long long cnt[MAXC][MAXC], dp[1<<20];
vector<int> p[MAXC];
// cnt[i][j]  the number of cheange put all i before j

int main()
{
    cin >> n;
    for (int i = 1, a; i <= n ; ++i) {
        cin >> a;
        p[a-1].push_back(i);
    }
    for (int i = 0; i < 20; ++i) {
        if (!p[i].size()) continue;
        for (int j = 0; j < 20; ++j) {
            if (!p[j].size() || i == j) continue;
            for (int pi = 0, pj = 0; pi < p[i].size(); ++pi) {
                while (pj+1 < p[j].size() && p[i][pi] > p[j][pj+1]) ++pj;
                if (p[i][pi] > p[j][pj]) cnt[i][j] += pj+1;
            }
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int cur = 1; cur < (1<<20); ++cur) {
        for (int i = 0; i < 20; ++i) {
            if (cur&(1<<i)) {
                long long sum = 0;
                for (int j = 0; j < 20; ++j) {
                    if (i != j && (cur&(1<<j))) {
                        sum += cnt[i][j];
                    }
                }
                dp[cur] = min(dp[cur], dp[cur^(1<<i)]+sum);
            }
        }
    }
    cout << dp[(1<<20)-1] << endl;
    return 0;
}
