#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;
int a[Maxn], last[Maxn], nex[Maxn], cnt[Maxn], tr[Maxn];
long long res, sum;

// 单点修改 add(x, k);
// 区间修改 add(x, k); add(y+1, -k);
inline void add(int i, int k)
{
    for( ; i <= n; i += i & -i) tr[i] += k;
}
// 单点查询
inline int query(int x)
{
    int res = 0;
    for( ; x; x -= x & -x) res += tr[x];
    return res;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        // 之前没出现过
        if(!last[a[i]])
        {
            // 记录这个值上一次出现的位置
            last[a[i]] = i;
            cnt[i] = cnt[i-1]+1;
        }
        else
        {
            // 记录这个值下一次出现的位置
            nex[last[a[i]]] = i;
            last[a[i]] = i;
            cnt[i] = cnt[i-1];
        }
        // [1, 1~n]的总和
        sum += cnt[i];
    }
    res += sum;
    for(int i = 1; i < n; ++i)
    {
        // 计算[i+1, i~n]
        // 删除 cnt[i]
        sum -= query(i)+cnt[i];
        // a[i] 下一次出现的位置
        int pos = nex[i] ? nex[i] : n+1;
        // 对[i+1, pos-1] 的影响
        sum -= pos-i-1;
        // [i+1, pos-1] -1
        add(i+1, -1); add(pos, 1);
        res += sum;
    }
    printf("%lld\n", res);
    return 0;
}
