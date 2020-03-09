/*
 * @Author: Kaizyn
 * @Date: 2020-03-09 19:00:57
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 19:49:52
 * @FilePath: \Code\HDU\hdu4474.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, tot;
int vis[N], use[10], pw10[N];
queue<int> q;

struct Node
{
    int mod;
    vector<int> num;
} a[N];

inline void print(const int &x)
{
    for (auto it = a[x].num.rbegin(); it != a[x].num.rend(); ++it)
        printf("%d", *it);
    putchar('\n');
}

inline void BFS()
{
    vector<int>().swap(a[0].num);
    a[0].mod = 0;
    tot = 1;
    queue<int>().swap(q);
    q.push(0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i <= 9; ++i) if (!use[i]) {
            a[tot].mod = (pw10[a[u].num.size()]*i+a[u].mod)%n;
            a[tot].num = a[u].num;
            a[tot].num.emplace_back(i);
            if (i && a[tot].mod == 0) { print(tot); return; }
            if (vis[a[tot].mod]) continue;
            vis[a[tot].mod] = 1;
            q.push(tot);
            ++tot;
        }
    }
    puts("-1");
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0;
    while (cin >> n >> m) {
        memset(use, 0, sizeof use);
        memset(vis, 0, sizeof(int)*(n+3));
        for (int i = 1, d; i <= m; ++i) {
            cin >> d;
            use[d] = 1;
        }
        for (int i = 0; i < n; ++i) vector<int>().swap(a[i].num);
        pw10[0] = 1;
        for (int i = 1; i <= n; ++i) pw10[i] = pw10[i-1]*10%n;
        printf("Case %d: ", ++T);
        BFS();
    }
    return 0;
}