#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;
const int M = 1e6+7;
const int NN = 1e7+7;

int n, m, top;
set<pair<int, int>> s;

struct Node
{
    int l, r;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.l < n2.l;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.l >> node.r;
    }
} a[N];

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
} dsu;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    m = n*2;
    dsu.init(n);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a+1, a+n+1);
    long long edge = 0;
    for (int i = 1; i <= n; ++i) {
        auto head = s.upper_bound({a[i].l, i}),
             tail = s.upper_bound({a[i].r, i});
        while (head != tail) {
            if (!dsu.merge(i, head->second)) {
                cout << "NO" << endl;
                return 0;
            }
            ++edge;
            ++head;
        }
        s.insert({a[i].r, i});
    }
    cout << (edge == n-1 ? "YES" : "NO") << endl;
    return 0;
}

