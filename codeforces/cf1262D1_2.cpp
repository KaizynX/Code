#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m;

struct Node
{
    int v, id;
    friend bool operator < (const Node &x, const Node &y) {
        return x.v == y.v ? x.id < y.id : x.v > y.v;
    }
} a[N];

inline bool cmp(const Node &x, const Node &y) {
    return x.id < y.id;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    cin >> m;
    for (int i = 1, k, p; i <= m; ++i) {
        cin >> k >> p;
        vector<Node> v;
        for (int j = 1; j <= k; ++j) v.push_back(a[j]);
        sort(v.begin(), v.end(), cmp);
        cout << v[p-1].v << endl;
    }
    return 0;
}
