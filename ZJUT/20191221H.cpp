#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e6+7;

struct Node
{
    int p, v;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.v == n2.v ? n1.p < n2.p : n1.v > n2.v;
    }
} a[N];

inline bool cmp(const Node &n1, const Node &n2) { return n1.p < n2.p; }
inline bool cmp2(const Node &n1, const Node &n2) { 
    return n1.v == n2.v ? n1.p > n2.p : n1.v > n2.v;
}

int n;
vector<Node> v[2];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].p;
    for (int i = 1; i <= n; ++i) cin >> a[i].v;
    sort(a+1, a+n+1, cmp);
    int df;
    for (int i = 1; i <= n; ++i) if (a[i].v == -1) df = i;
    int m = 1, u = 0;
    while (m*4 <= df) m *= 4;
    swap(a[df], a[m]);
    df = m;
    for (int i = m+1; i <= n; ++i) v[0].push_back(a[i]);
    for (int i = 1; i < m; i *= 4, u ^= 1) {
        sort(v[u].begin(), v[u].end(), cmp);
        reverse(v[u].begin(), v[u].end());
        v[u^1].clear();
        priority_queue<Node> q;
        for (int j = 0; j < (int)v[u].size(); ++j) {
            q.push(v[u][j]);
            if (j%4 == 0) v[u^1].push_back(q.top()), q.pop();
        }
    }
    long long res = 0;
    for (int i = m; i < n; i *= 4, u ^= 1) {
        sort(v[u].begin(), v[u].end(), cmp2);
#ifdef DEBUG
        for (auto pp : v[u]) cout << "(" << pp.p << ", " << pp.v << ") ";
        cout << endl;
#endif
        for (int j = 0; j < 3; ++j) {
            if (v[u].back().p > a[df].p) res += v[u].back().v;
            v[u].pop_back();
        }
        sort(v[u].begin(), v[u].end(), cmp);
        reverse(v[u].begin(), v[u].end());
        v[u^1].clear();
        priority_queue<Node> q;
        for (int j = 0; j < (int)v[u].size(); ++j) {
            q.push(v[u][j]);
            if (j%4 == 0) v[u^1].push_back(q.top()), q.pop();
        }
    }
    cout << res << endl;
    return 0;
}
