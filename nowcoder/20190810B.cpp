#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;
int a[Maxn], last[Maxn], nex[Maxn], cnt[Maxn], tr[Maxn];
long long res, sum;

// �����޸� add(x, k);
// �����޸� add(x, k); add(y+1, -k);
inline void add(int i, int k)
{
    for( ; i <= n; i += i & -i) tr[i] += k;
}
// �����ѯ
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
        // ֮ǰû���ֹ�
        if(!last[a[i]])
        {
            // ��¼���ֵ��һ�γ��ֵ�λ��
            last[a[i]] = i;
            cnt[i] = cnt[i-1]+1;
        }
        else
        {
            // ��¼���ֵ��һ�γ��ֵ�λ��
            nex[last[a[i]]] = i;
            last[a[i]] = i;
            cnt[i] = cnt[i-1];
        }
        // [1, 1~n]���ܺ�
        sum += cnt[i];
    }
    res += sum;
    for(int i = 1; i < n; ++i)
    {
        // ����[i+1, i~n]
        // ɾ�� cnt[i]
        sum -= query(i)+cnt[i];
        // a[i] ��һ�γ��ֵ�λ��
        int pos = nex[i] ? nex[i] : n+1;
        // ��[i+1, pos-1] ��Ӱ��
        sum -= pos-i-1;
        // [i+1, pos-1] -1
        add(i+1, -1); add(pos, 1);
        res += sum;
    }
    printf("%lld\n", res);
    return 0;
}
