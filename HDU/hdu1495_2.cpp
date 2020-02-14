#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

struct Node
{
    int s, n, m, t;
};

int vis[N][N];
queue<Node> q;

inline void update(int s, int n, int m, int t)
{
    if (vis[n][m]) return;
    vis[n][m] = 1;
    q.push({s, n, m, t});
}

int main()
{
    int s, n, m;
    while (cin >> s >> n >> m && s|n|m) {
        if (s&1) {
            cout << "NO" << endl;
            continue;
        }
        memset(vis, 0, sizeof vis);
        queue<Node>().swap(q);
        q.push({s, 0, 0, 0});
        vis[0][0] = 1;
        int flag = 0;
        while (q.size()) {
            Node u = q.front();
            q.pop();
            if ((!u.s || !u.n || !u.m) && 
                (u.s == s/2 || u.n == s/2 || u.m == s/2)) {
                cout << u.t << endl;
                flag = 1;
                break;
            }
            // s -> n
            int d = min(u.s, n-u.n);
            update(u.s-d, u.n+d, u.m, u.t+1);
            // s -> m
            d = min(u.s, m-u.m);
            update(u.s-d, u.n, u.m+d, u.t+1);
            // n -> s
            update(u.s+u.n, 0, u.m, u.t+1);
            // m -> s
            update(u.s+u.m, u.n, 0, u.t+1);
            // n -> m
            d = min(u.n, m-u.m);
            update(u.s, u.n-d, u.m+d, u.t+1);
            // m -> n
            d = min(n-u.n, u.m);
            update(u.s, u.n+d, u.m-d, u.t+1);
        }
        if (!flag) cout << "NO" << endl;
    }
    return 0;
}
