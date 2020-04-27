/*
 * @Author: Kaizyn
 * @Date: 2020-04-23 22:09:13
 * @LastEditTime: 2020-04-24 00:55:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int M = 1e4+7;
const int T = 1e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct Queue{
	pii a[1<<23];
	unsigned int h:23,t:23;
	Queue(){h=t=0;}
	void push(pii x){a[t++]=x;}
	void pop(){++h;}
	bool empty(){return h==t;}
	pii front(){return a[h];}
	int size(){return t-h;}
	pii pop_getfront(){return a[h++];}
};

int n, m, g, r;
int d[M];
int dp[M][T];
bool vis[M][T];
// queue<pii> q;
Queue q;

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> d[i];
    cin >> g >> r;

    memset(dp, 0x3f, sizeof dp);
    sort(d+1, d+m+1);
    dp[1][0] = 0;
    vis[1][0] = 1;
    q.push({1, 0});
    while (q.size()) {
        int x = q.front().first,
            y = q.front().second;
        q.pop();
        #ifdef DEBUG
        cout << x << " " << y << endl;
        #endif
        for (int i = x-1, rest = (y ? y : g); i; --i) {
            rest -= d[i+1]-d[i];
            if (rest < 0) break;
            if (dp[i][rest] > dp[x][y]+(rest == 0)) {
                dp[i][rest] = dp[x][y]+(rest == 0);
                if (!vis[i][rest]) q.push({i, rest}), vis[i][rest] = 1;
            }
        }
        for (int i = x+1, rest = (y ? y : g); i <= m; ++i) {
            rest -= d[i]-d[i-1];
            if (rest < 0) break;
            if (dp[i][rest] > dp[x][y]+(rest == 0)) {
                dp[i][rest] = dp[x][y]+(rest == 0);
                if (!vis[i][rest]) q.push({i, rest}), vis[i][rest] = 1;
            }
        }
        vis[x][y] = 0;
    }
    int res = dp[m][0] < INF ? dp[m][0]*(g+r)-r : INF;
    for (int i = 1; i <= m; ++i) {
        if (n-d[i] <= g && dp[i][0] < INF) {
            res = min(res, dp[i][0]*(g+r)+n-d[i]);
        }
    }
    cout << (res >= INF ? -1 : res) << endl;
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