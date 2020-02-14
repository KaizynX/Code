#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const long long INF = 1e18;

int T, n;
map<long long, int> vis;
queue<long long> q;

inline void push(const long long &u, const long long &v)
{
    if (v > INF) return;
    if (vis.find(v) != vis.end()) return;
    vis[v] = vis[u]+1;
    q.push(v);
}

int main()
{
    cin >> T;
    while (T--) {
        queue<long long>().swap(q);
        vis.clear();
        cin >> n;
        q.push(n);
        vis[n] = 0;
        while (q.size()) {
            long long u = q.front();
            q.pop();
            if (u == 0) {
                cout << vis[u] << endl;
                break;
            }
            push(u, u+1);
            push(u, u-1);
            push(u, u*2);
            if (u%4 == 0) push(u, u/4);
        }
    }
    return 0;
}
