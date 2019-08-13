#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;

int T, n, len;
int p[Maxn], k[Maxn], pre[Maxn], nex[Maxn], used[Maxn], f[Maxn], res[Maxn];
// used[i] whether i in LIS
// f[i] max len of LIS (end by p[i])

struct Tree
{
    int tr[Maxn];
    void clear() { for(int i = 1; i <= n; ++i) tr[i] = 0; }
    void modify(int x, int v) { for(; x <= n; x += x&-x) tr[x] = max(tr[x], v); }
    // the max len of LIS (end by [1~x])
    int query(int x) {
        int ans = 0;
        for(; x; x -= x&-x) ans = max(ans, tr[x]);
        return ans;
    }
}ta;

inline void del(int i)
{
    nex[pre[i]] = nex[i];
    pre[nex[i]] = pre[i];
}

void LIS()
{
    ta.clear();
    len = 0;
    // get the max len of LIS
    for(int i = nex[0]; i <= n; i = nex[i]) {
        used[i] = 0;
        f[i] = ta.query(p[i]-1)+1;
        ta.modify(p[i], f[i]);
        len = max(len, f[i]);
    }
    // get the member of LIS
    for(int i = pre[n+1], now = len, last = Maxn; i; i = pre[i])
        if (f[i] == now && p[i] < last) {

            now--;
            last = p[i];
            used[i] = 1;
        }
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", p+i);
            pre[i] = i-1; nex[i] = i+1;
        }
        nex[0] = 1; pre[n+1] = n;
        for(int i = 1; i <= n; ++i) scanf("%d", k+i);
        LIS();
        res[n] = len;
        for(int i = n; i > 1; --i) {
            del(k[i]);
            if (used[k[i]]) LIS();
            res[i-1] = len;
        }
        for(int i = 1; i < n; ++i) printf("%d ", res[i]);
        printf("%d\n", res[n]);
    }
    return 0;
}
