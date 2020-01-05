#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, cur;
int a[N], vis[N];
int dp[2][N];

inline void update(int &x, const int y) { if (x == -1 || y < x) x = y; }

int f(int b, int x) {
    if (b == a[x]%2) return 0;
    // if (dp[b][x] != -1) return dp[b][x];
    if (x < cur) return dp[b][x];
    vis[x] = 1;
    if (x-a[x] >= 1 && !vis[x-a[x]]) {
        int tmp = f(b, x-a[x]);
        if (tmp != -1) update(dp[b][x], tmp+1);
    }
    if (x+a[x] <= n && !vis[x+a[x]]) {
        int tmp = f(b, x+a[x]);
        if (tmp != -1) update(dp[b][x], tmp+1);
    }
    vis[x] = 0;
    return dp[b][x];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        cur = i;
        cout << f(a[i]&1^1, i) << " \n"[i==n];
    }
    return 0;
}

