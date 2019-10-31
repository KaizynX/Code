#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 2e5+7;

struct Node
{
    int l, r, id;
    Node(){}
    Node(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
    friend bool operator < (const Node &x, const Node &y) {
        return x.r < y.r;
    }
} a[N];

bool cmp(const Node &x, const Node &y) { return x.l < y.l; }

int n, k, cnt;
multiset<Node> s;
vector<int> res;

int main()
{
    int ll = N, rr = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        a[i].id = i;
        cin >> a[i].l >> a[i].r;
        ll = min(ll, a[i].l);
        rr = max(rr, a[i].r);
    }
    sort(a+1, a+n+1, cmp);
    for (int i = ll, p = 1; i <= rr; ++i) {
        while (s.size() && s.begin()->r < i)
            s.erase(s.begin());
        while (p <= n && a[p].l == i)
            s.insert(a[p++]);
        while ((int)s.size() > k) {
            ++cnt;
            res.push_back(s.rbegin()->id);
            s.erase(prev(s.end()));
        }
    }
    cout << cnt << endl;
    for (int i : res) cout << i << " ";
    cout << endl;
    return 0;
}
