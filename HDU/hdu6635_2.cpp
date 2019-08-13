#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;

int T, n;
int p[Maxn], k[Maxn], pre[Maxn], nex[Maxn], f[Maxn], res[Maxn];
int lis[Maxn], cnt;

inline void del(int i)
{
    nex[pre[i]] = nex[i];
    pre[nex[i]] = pre[i];
}

inline void LIS()
{
    for(int i = 0; i < cnt; ++i)
    {
        f[lis[i]] = 0;
        lis[i] = 0;
    }
    cnt = 0;
    for(int i = nex[0]; i <= n; i = nex[i])
    {
        int pos = upper_bound(lis, lis+cnt, p[i])-lis;
        // lis[pos] > p[i]
        if(pos == cnt)
        {
            lis[cnt++] = p[i];
            f[p[i]] = 1;
        }
        else
        {
            f[lis[pos]] = 0;
            f[p[i]] = 1;
            lis[pos] = p[i];
        }
    }
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", p+i);
            pre[i] = i-1; nex[i] = i+1;
        }
        nex[0] = 1; pre[n+1] = n;
        for(int i = 1; i <= n; ++i) scanf("%d", k+i);
        LIS();
        res[n] = cnt;
        for(int i = n; i > 1; --i)
        {
            del(k[i]);
            if(f[p[k[i]]]) LIS();
            res[i-1] = cnt;
        }
        for(int i = 1; i < n; ++i) printf("%d ", res[i]);
        printf("%d\n", res[n]);
    }
    return 0;
}
