#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const long long INF = 1e18;

int T, cnt;
map<long long, int> mp, vis;
long long a[10];
queue<long long> q;

inline void push(const long long &u, const long long &v)
{
    if (v > INF) return;
    if (vis.find(v) == vis.end()) {
        vis[v] = vis[u]+1;
        q.push(v);
        if (mp.find(v) != mp.end()) {
            ++cnt;
            if (--mp[v] == 0) mp.erase(v);
        }
    }
}

int main()
{
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> a[i];
        ++mp[a[i]];
    }
    q.push(0);
    vis[0] = 0;
    long long u;
    while (q.size() && cnt < T) {
        u = q.front();
        q.pop();
#ifdef DEBUG
        cout << u << " " << vis[u] << endl;
#endif
        push(u, u+1);
        push(u, u*4);
        if (u > 1) push(u, u-1);
        if (u%2 == 0) push(u, u/2);
    }
    for (int i = 1; i <= T; ++i)
        cout << vis[a[i]] << endl;
    return 0;
}
