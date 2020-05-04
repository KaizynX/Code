/*
 * @Author: Kaizyn
 * @Date: 2020-05-03 17:07:08
 * @LastEditTime: 2020-05-03 17:21:03
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 1e6+7;

int n, m;
int a[N], log_2[N];

template <typename T, typename U = std::greater<T>>
struct ST
{
    static const int NN = (int)log2(N)+3;
    static const T INF = 1e9;
    int lg2[N];
    U cmp = U();
    T rmq[N][NN]; // rmq[i][j] ==> [i, i+2^j-1]
    ST() {
        fill(rmq[0], rmq[0]+N*NN, cmp(-INF, +INF) ? INF : -INF);
        for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    }
    T& operator [] (const int &i) { return rmq[i][0]; }
    void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
    void build(T a[], const int &n) {
        for (int i = n; i; --i) {
            rmq[i][0] = a[i];
            for (int j = 1; j <= lg2[n-i+1]; ++j)
                rmq[i][j] =  mv(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
        }
    }
    T query(const int &l, const int &r) {
        int k = lg2[r-l+1];
        return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
    }
};
ST<int, greater<int>> st;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; ++i) log_2[i] = log_2[i>>1]+1;
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    st.init();
    st.build(a, n);
    int l, r;
    while (m--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", st.query(l, r));
    }
    return 0;
}