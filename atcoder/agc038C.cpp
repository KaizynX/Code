#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int A = 1e6+7;
const int P = 8e4+7;
const int MOD = 998244353;

int n, cnt, res;
int a[N], check[A], prime[P], f[A];

struct BinaryIndexedTree
{
    // set your type
    typedef int T;
    T tr[23];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} num[P], tot[P];

inline void init()
{
    check[1] = true;
    for(int i = 2; i <= 1000000; ++i)
    {
        if(!check[i]) prime[++cnt] = i, f[i] = cnt;
        for(int j = 1; j <= cnt && i*prime[j] <= 1000000; ++j)
        {
            check[ i*prime[j] ] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        for(int j = 1; 1ll*prime[j]*prime[j] <= a[i]; ++j)
            if(a[i]%prime[j] == 0) {
                int k = 0;
                for(; a[i]%prime[j] == 0; a[i] /= prime[j]) ++k;
                ( res += 1ll*tot[j].query(k)*prime[j]%MOD ) %= MOD;
                ( res += 1ll*num[j].query(k+1, 20)*k*prime[j]%MOD ) %= MOD;
                num[j].update(k, 1);
                tot[j].update(k, k);
            }
        if(a[i] > 1) {
            int k = a[i], j = f[a[i]];
            ( res += 1ll*tot[j].query(k)*prime[j]%MOD ) %= MOD;
            ( res += 1ll*num[j].query(k+1, 20)*k*prime[j]%MOD ) %= MOD;
            num[j].update(k, 1);
            tot[j].update(k, k);
        }
    }
    printf("%d\n", res);
    return 0;
}
