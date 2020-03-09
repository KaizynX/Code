/*
 * @Author: Kaizyn
 * @Date: 2020-03-09 20:13:03
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 20:22:18
 * @FilePath: \Code\HDU\hdu4474_3.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;

int n, m, tot;
int vis[N], use[10];
queue<int> q;

struct Node
{
    int mod, pre, num;
} a[N];

inline void print(const int &x)
{
    string res;
    for (int i = x; i; i = a[i].pre)
        res += (char)('0'+a[i].num);
    reverse(res.begin(), res.end());
    cout << res << endl;
}

inline void BFS()
{
    a[0] = {0,0,0};
    tot = 1;
    queue<int>().swap(q);
    q.push(0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u && a[u].mod == 0) { print(u); return; }
        #ifdef DEBUG
        print(u);
        #endif
        for (int i = 0; i <= 9; ++i) if (!use[i]) {
            a[tot] = {(a[u].mod*10+i)%n, u, i};
            if ((!i && !u) || vis[a[tot].mod]) continue;
            vis[a[tot].mod] = 1;
            q.push(tot);
            ++tot;
        }
    }
    cout << -1 << endl;
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
        cout << "Case " << ++T << ": ";
        // printf("Case %d: ", ++T);
        BFS();
    }
    return 0;
}