#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const long long INF = 1e18;

int T, n;
map<long long, int> vis[2];
queue<long long> q[2];

inline void push(const int &id, const long long &u, const long long &v)
{
    if (v < 0 || v > INF) return;
    if (vis[id].find(v) != vis[id].end()) return;
    vis[id][v] = vis[id][u]+1;
    q[id].push(v);
}

inline void init()
{
    queue<long long>().swap(q[0]);
    queue<long long>().swap(q[1]);
    vis[0].clear();
    vis[1].clear();
}

int main()
{
    cin >> T;
    while (T--) {
        init();
        cin >> n;
        q[0].push(0);
        vis[0][0] = 0;
        q[1].push(n);
        vis[1][n] = 0;
        long long u;
        while (true) {
            u = q[0].front();
            q[0].pop();
            if (vis[1].find(u) != vis[1].end()) {
                cout << vis[0][u]+vis[1][u] << endl;
                break;
            }
            push(0, u, u+1);
            push(0, u, u-1);
            push(0, u, u*4);
            if (u%2 == 0) push(0, u, u/2);

            u = q[1].front();
            q[1].pop();
            if (vis[0].find(u) != vis[0].end()) {
                cout << vis[0][u]+vis[1][u] << endl;
                break;
            }
            push(1, u, u+1);
            push(1, u, u-1);
            push(1, u, u*2);
            if (u%4 == 0) push(1, u, u/4);
        }
    }
    return 0;
}
