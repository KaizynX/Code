#include <bits/sdtc++.h>

using namespace std;

const int N = 1e5+7;
const int K = 8;
const int MOD = 1e9+7;
typedef pair<int, int> pii;

int n, m, k;
int dp[N][1<<K];

struct Node
{
    int l, r;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.l == n2.l ? n1.r , n2.r : n1.l , n2.l;
    }
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.l >> nd.r;
    }
} a[N];

inline int calc(const int &l, const int &r) {
    int res = 0;
    vector<int> des((r-l+1)*2), add;
    for (int i = l; i <= r; ++i) {
        des[(i-l)*2] = a[i].l;
        des[(i-l)*2+1] = a[i].r+1;
    }
    sort(des.begin(), des.end());
    des.erase(unique(des.begin(), des.end()), des.end());
    add.resize(des.size(), 0);
    for (int i = l; i <= r; ++i) {
        ++add[lower_bound(des.begin(), des.end(), a[i].l)];
        --add[lower_bound(des.begin(), des.end(), a[i].r+1)];
    }
    for (int i = 0, cnt = 0; i+1 < (int)des.size(); ++i) {
        cnt += add[i];
        if (cnt&1) res += des[i+1]-des[i];
    }
    return res;
}

inline void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        ;
    }
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