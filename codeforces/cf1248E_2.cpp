#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, p;
long long res[N];

struct BinaryIndexedTree
{
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

struct Node
{
    int id, t;
    friend bool operator < (const Node &x, const Node &y) { return x.t < y.t; }
} a[N];

priority_queue<int, vector<int>, greater<int> > que, seat;

int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].t;
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    int cur = 1;
    long long now = 0;
    while (que.size() || seat.size() || cur <= n) {
        if (que.empty() && seat.empty() && cur <= n && now < a[cur].t) now = a[cur].t;
        // sb want water
        while (cur <= n && a[cur].t <= now) seat.push(a[cur++].id);
        // sb come to queue
        if (seat.size() && !BIT.query(seat.top())) {
            que.push(seat.top());
            BIT.update(seat.top(), 1);
            seat.pop();
        }
        // sb get water
        if (que.size()) {
            res[que.top()] = (now += p);
            BIT.update(que.top(), -1);
            que.pop();
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " \n"[i==n];
    }
    return 0;
}
