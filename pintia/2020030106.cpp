#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

struct Node
{
    int x, y, z, id;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.x >> nd.y >> nd.z;
    }
    friend bool operator < (const Node &n1, const Node &n2) {
        if (n1.x != n2.x) return n1.x < n2.x;
        if (n1.y != n2.y) return n1.y < n2.y;
        return n1.z < n2.z;
    }
    friend bool operator == (const Node &n1, const Node &n2) {
        return n1.id == n2.id;
    }
} a[N];

int n, dx, dy, dz;
set<Node> s;

inline void solve()
{
    cin >> n >> dx >> dy >> dz;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i].id = i;
    }
    int res = n+1;
    sort(a+1, a+n+1, [](const Node &n1, const Node &n2) { return n1.z < n2.z; });
    for (int i = 1, l = 1, r = 1; i <= n; ++i) {
        while (l < r && a[i].z-a[l].z > dz) s.erase(s.find(a[l++]));
        while (r <= n && a[r].z-a[i].z <= dz) s.insert(a[r++]);
        for (auto it = s.lower_bound({a[i].x-dx, 0, 0, 0}); it != s.end(); ++it) {
            if (it->x-a[i].x > dx) break;
            if (it->id >= a[i].id) continue;
            if (abs(a[i].y-it->y) <= dy) {
                res = min(res, a[i].id);
                break;
            }
        }
    }
    cout << (res > n ? 0 : res) << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}