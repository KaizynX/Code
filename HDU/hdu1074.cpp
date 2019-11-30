#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int INF = 1e9;

int T, n;
int d[N], c[N], dp[1<<N], t[1<<N], last[1<<N];
string s[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s[i] >> d[i] >> c[i];
        }
        for (int i = 1; i < (1<<n); ++i) {
            t[i] = 0;
            for (int j = 0; j < n; ++j)
                if ((i>>j)&1) t[i] += c[j];
        }
        for (int i = 1; i < (1<<n); ++i) {
            dp[i] = INF;
            for (int j = n-1; j >= 0; --j) {
                if ((i>>j)&1^1) continue;
                int tmp = dp[i^(1<<j)]+max(0, t[i]-d[j]);
                if (tmp < dp[i]) {
                    dp[i] = tmp;
                    last[i] = j;
                }
            }
        }
        cout << dp[(1<<n)-1] << endl;
        vector<int> k;
        for(int cur = (1<<n)-1, p = last[cur]; cur; cur ^= 1<<p, p = last[cur]) {
            k.emplace_back(p);
        }
        reverse(k.begin(), k.end());
        for (int i : k) cout << s[i] << endl;
    }
    return 0;
}
