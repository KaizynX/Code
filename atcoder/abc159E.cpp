/*
 * @Author: Kaizyn
 * @Date: 2020-03-22 20:18:39
 * @LastEditTime: 2020-03-22 20:56:33
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 15;
const int M = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, k;
char a[N][M];
int num[N];

inline bool check(const int &i)
{
    for (int l = 0, now = 0; l < n; ++l) {
        now += num[l];
        if (now > k) return false;
        if ((i>>l)&1) now = 0;
    }
    return true;
}

inline void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = INF;
    // cut in horizontal (i>>j)&1 if cur between j && j+1
    for (int i = 0, cnt; i < (1<<(n-1)); ++i) {
        memset(num, 0, sizeof num);
        cnt = __builtin_popcount(i);
        // cut in vertical
        for (int j = 0, flag; j < m; ++j) {
            flag = 0;
            for (int l = 0; l < n; ++l) {
                if (a[l][j] == '1') ++num[l];
            }
            if (check(i)) continue;
            // add the col exceed, cut between j-1 && j
            ++cnt;
            for (int l = 0; l < n; ++l) {
                num[l] = a[l][j] == '1';
            }
            if (!check(i)) { cnt = INF; break; }
        }
        res = min(res, cnt);
    }
    cout << res << endl;
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
