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
    int x, y, z;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.x >> nd.y >> nd.z;
    }
    friend bool operator < (const Node &n1, const Node &n2) {
        if (n1.x != n2.x) return n1.x < n2.x;
        if (n1.y != n2.y) return n1.y < n2.y;
        return n1.z < n2.z;
    }
} a[N], cur;

long long get_hash(const Node &nd)
{
    static const int M1 = 998244353, M2 = 19260817, M3 = 954169327, M4 = 1e9+7;
    return (nd.x*M1+nd.y*M2+nd.z*M3)%M4;
}

int n, dx, dy, dz;
unordered_map<long long, int> mp;

inline bool check(const Node &n1, const Node &n2)
{
    return abs(n1.x-n2.x) <= dx && abs(n1.y-n2.y) <= dy && abs(n1.z-n2.z) <= dz;
}

inline int solve()
{
    cin >> n >> dx >> dy >> dz;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cur = {a[i].x/dx, a[i].y/dy, a[i].z/dz};
        for (int x = -1; x <= 1; ++x)
        for (int y = -1; y <= 1; ++y)
        for (int z = -1; z <= 1; ++z) {
            long long tmp = get_hash({cur.x+x, cur.y+y, cur.z+z});
            if (mp.count(tmp) && check(a[mp[tmp]], a[i])) return i;
        }
        mp.insert({get_hash(cur), i});
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}