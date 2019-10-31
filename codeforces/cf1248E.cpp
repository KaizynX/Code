#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, p;
long long res[N];

struct Node
{
    int id, t;
    friend bool operator < (const Node &x, const Node &y) {
        return x.id > y.id;
    }
} a[N];

inline bool cmp(const Node &x, const Node &y) { return x.t < y.t; }

priority_queue<Node> q;

int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].t;
        a[i].id = i;
    }
    sort(a+1, a+n+1, cmp);
    int cur = 1;
    long long now = 0;
    while (q.size() || cur <= n) {
        if (q.empty() && cur <= n && now < a[cur].t) now = a[cur].t;
        while (cur <= n && a[cur].t <= now) {
            q.push(a[cur]);
            ++cur;
        }
        
        if (q.empty()) continue;
        Node person = q.top();
        q.pop();
        res[person.id] = (now += p);
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " \n"[i==n];
    }
    return 0;
}
