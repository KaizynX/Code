/*
 * @Author: Kaizyn
 * @Date: 2020-04-23 22:09:06
 * @LastEditTime: 2020-04-23 23:49:54
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int num[] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};

int n, k;
int a[N];
bool dp[N][N][10], yep[N][N];
string str;

inline int change(const string &s) {
    int res = 0;
    for (const char &c : s) {
        res = res*2+(c-'0');
    }
    return res;
} 

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        a[i] = change(str);
        for (int j = 0; j <= k; ++j) {
            yep[i][j] = 0;
            memset(dp[i][j], 0, sizeof dp[i][j]);
        }
    }
    memset(yep[n+1], 0, sizeof yep[n+1]);
    yep[n+1][0] = 1;
    // for (int i = 1; i <= k; ++i) memset(dp[n+1][i], 0, sizeof dp[n+1][i]);
    // for (int i = 0; i < 10; ++i) dp[n+1][0][i] = 1;
    for (int i = n; i; --i) {
        for (int j = 0, c; j < 10; ++j) {
            if ((num[j]|a[i]) != num[j]) continue;
            c = __builtin_popcount(num[j]-a[i]);
            for (int l = c; l <= k; ++l) {
                if (yep[i+1][l-c]) {
                    dp[i][l][j] = 1;
                    yep[i][l] = 1;
                }
            }
        }
    }
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            cout << yep[i][j] << " \n"[j==k];
        }
    }
    #endif
    if (!yep[1][k]) return void(cout << -1 << endl);
    for (int i = 1; i <= n; ++i) {
        for (int j = 9; j >= 0; --j) {
            if (dp[i][k][j]) {
                cout << j;
                k -= __builtin_popcount(num[j]-a[i]);
                break;
            }
        }
    }
    cout << endl;
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