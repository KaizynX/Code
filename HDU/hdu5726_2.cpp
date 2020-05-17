/*
 * @Author: Kaizyn
 * @Date: 2020-05-05 18:24:58
 * @LastEditTime: 2020-05-05 19:49:43
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int a[N], lg2[N];
int rmq[N][20];
map<int, long long> cnt;

void init() {
    for (int i = n; i; --i) {
        rmq[i][0] = a[i];
        for (int j = 1; j <= lg2[n-i+1]; ++j)
            rmq[i][j] =  __gcd(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
}

int query(const int &l, const int &r) {
    if (l > r) return query(r, l);
    int k = lg2[r-l+1];
    return __gcd(rmq[l][k], rmq[r-(1<<k)+1][k]);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        init();
        cnt.clear();
        for (int i = 1, g; i <= n; ++i) {
            g = a[i];
            for (int j = i, last = i; j <= n; ++j) {
                g = __gcd(g, a[j]);
                for (int b = lg2[n-last]; b >= 0 && j <= n; --b) {
                    if (j+(1<<b) <= n && __gcd(g, rmq[j+1][b]) == g)
                        j += 1<<b;
                }
                cnt[g] += j-last+1;
                last = j+1;
                #ifdef DEBUG
                printf("%d ", j);
                #endif
            }
            #ifdef DEBUG
            printf("##%d\n", i);
            #endif
        }

        scanf("%d", &m);
        printf("Case #%d:\n", t);
        for (int i = 1, l, r, g; i <= m; ++i) {
            scanf("%d%d", &l, &r);
            g = query(l, r);
            printf("%d %lld\n", g, cnt[g]);
        }
    }
    return 0;
}