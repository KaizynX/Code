#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;

int n, m, q;
char a[N][N];
int sum[N][N][4], val[N][N], log_2[N], mp[256];

template <typename T, typename U = std::greater<T>>
struct ST
{
    static const int NN = (int)log2(N)+3;
    static const T INF = 1e9;
    U cmp = U();
    T rmq[N][N][NN][NN]; // rmq[i][j][k][l] [i, j] [i+2^k-1, j+2^l-1]
    ST() { init(); }
    ST(const T &val) { init(val); }
    T& operator [] (const int &i) { return rmq[i][0]; }
    void init(){ fill(rmq[0][0][0], rmq[0][0][0]+N*N*NN*NN, cmp(-INF, +INF) ? INF : -INF); }
    void init(const T &val) { fill(rmq[0][0][0], rmq[0][0][0]+N*N*NN*NN, val); }
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
    void build(T a[N][N], const int &n, const int &m) {
        for (int k = 0; k <= log_2[n]; ++k)
        for (int l = 0; l <= log_2[m]; ++l)
        for (int i = 1; i+(1<<k)-1 <= n; ++i)
        for (int j = 1; j+(1<<l)-1 <= m; ++j) {
            T &cur = rmq[i][j][k][l];
            if (!k && !l) cur = a[i][j];
            else if (!l) cur = mv(rmq[i][j][k-1][l], rmq[i+(1<<(k-1))][j][k-1][l]);
            else cur = mv(rmq[i][j][k][l-1], rmq[i][j+(1<<(l-1))][k][l-1]);
        }
    }
    T query(const int &r1, const int &c1, const int &r2, const int &c2) {
        int k = log_2[r2-r1+1], l = log_2[c2-c1+1];
        return mv(mv(rmq[r1][c1][k][l], rmq[r2-(1<<k)+1][c2-(1<<l)+1][k][l]),
                  mv(rmq[r2-(1<<k)+1][c1][k][l], rmq[r1][c2-(1<<l)+1][k][l]));
    }
};
ST<int, greater<int>> st;

inline int count(const int &i, const int &j, const int &k, const int &c)
{
    return sum[i][j][c]-sum[i-k][j][c]-sum[i][j-k][c]+sum[i-k][j-k][c];
}

inline bool is_logo(const int &i, const int &j, const int &k)
{
    return count(i, j, k, 0) == k*k && count(i, j+k, k, 1) == k*k &&
           count(i+k, j, k, 2) == k*k && count(i+k, j+k, k, 3) == k*k;
}

inline bool check(const int &r1, const int &c1, const int &r2, const int &c2, const int &mid)
{
    return st.query(r1+mid-1, c1+mid-1, r2-mid, c2-mid) >= mid;
}

int main()
{
    mp['R'] = 0;
    mp['G'] = 1;
    mp['Y'] = 2;
    mp['B'] = 3;
    for (int i = 2; i < N; ++i) log_2[i] = log_2[i>>1]+1;

    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", a[i]+1);
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k <= 4; ++k)
                sum[i][j][k] = sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k];
            ++sum[i][j][mp[(int)a[i][j]]];
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = min({i, j, n-i, m-j}); k; --k)
                if (is_logo(i, j, k)) {
                    val[i][j] = k;
                    break;
                }
    st.build(val, n, m);
    int r1, r2, c1, c2;
    while (q--) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int l = 0, r = min((r2-r1+1)/2, (c2-c1+1)/2);
        while (l < r) {
            int mid = (l+r+1)>>1;
            if (check(r1, c1, r2, c2, mid)) l = mid;
            else r = mid-1;
        }
        printf("%d\n", l*l*4);
    }
    return 0;
}
