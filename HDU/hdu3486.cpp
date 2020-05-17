/*
 * @Author: Kaizyn
 * @Date: 2020-05-05 18:24:58
 * @LastEditTime: 2020-05-05 18:30:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T, typename U = std::greater<T>>
struct ST
{
    static const int NN = (int)log2(N)+3;
    static const T INF = 1e9;
    int lg2[N];
    U cmp = U();
    T rmq[N][NN]; // rmq[i][j] ==> [i-2^j+1, i]
    ST() {
        fill(rmq[0], rmq[0]+N*NN, cmp(-INF, +INF) ? INF : -INF);
        for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    }
    T& operator [] (const int &i) { return rmq[i][0]; }
    void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
    void build(T a[], const int &n) {
        for (int i = 1; i <= n; ++i) {
            rmq[i][0] = a[i];
            for (int j = 1; j <= lg2[i]; ++j)
                rmq[i][j] =  mv(rmq[i][j-1], rmq[i-(1<<(j-1))][j-1]);
        }
    }
    T query(const int &l, const int &r) {
        if (l > r) return query(r, l);
        int k = lg2[r-l+1];
        return mv(rmq[r][k], rmq[l+(1<<k)-1][k]);
    }
};

int n, k;
int a[N];
ST<int> st;

inline bool check(const int &m) {
    int sum = 0, part = n/m;
    for (int i = 1; i <= m; ++i) {
        sum += st.query(i*part-part+1, i*part);
    }
    return sum > k;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> k && !(n == -1 && k == -1)) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        st.build(a, n);
        int res = -1, l = 1, r = n, mid;
        while (l <= r) {
            mid = (l+r)>>1;
            if (check(mid)) {
                res = res == -1 ? mid : min(res, mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        cout << res << endl;
    }
    return 0;
}