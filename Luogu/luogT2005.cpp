#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int MOD = 1e9+7;

int n, m;
int b[Maxn];

struct Tree
{
    int l, r;
    long long v1, v2;
} tr[Maxn<<2];

typedef pair<long long, long long> llpair;
void exgcd(int, int, int&, int&);
inline int mul_inverse(int);
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1|1; }
inline void push_up(int);
void build_tree(int, int, int);
void update_tree(int, int, int);
llpair query_tree(int, int, int);

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", b+i);
    build_tree(1, 1, n);

    int c, a, b;
    while(m--)
    {
        scanf("%d%d%d", &c, &a, &b);
        if(c == 1) update_tree(1, a, b);
        else
        {
            int num = b-a+1, inv = mul_inverse(num);
            llpair now = query_tree(1, a, b);
            long long ave = now.first*inv%MOD;
            // d = inv[n]*(sum(ai^2)-2a*sum(ai)+n*a^2);
            long long d = (now.second-2*ave*now.first%MOD+ave*ave%MOD*num%MOD);
            d = (d%MOD+MOD)*inv%MOD;
            printf("%d\n", (int)d);
        }
    }
    return 0;
}

inline void push_up(int i)
{
    tr[i].v1 = (tr[ls(i)].v1+tr[rs(i)].v1)%MOD;
    tr[i].v2 = (tr[ls(i)].v2+tr[rs(i)].v2)%MOD;
}

void build_tree(int i, int l, int r)
{
    tr[i].l = l; tr[i].r = r;
    if(l == r)
    {
        tr[i].v1 = b[l];
        tr[i].v2 = 1ll*b[l]*b[l]%MOD;
        return;
    }
    int mid = (l+r)>>1;
    build_tree(ls(i), l, mid);
    build_tree(rs(i), mid+1, r);
    push_up(i);
}

void update_tree(int i, int p, int x)
{
    if(tr[i].l == tr[i].r && tr[i].l == p)
    {
        tr[i].v1 = x;
        tr[i].v2 = 1ll*x*x%MOD;
        return;
    }
    int mid = (tr[i].l+tr[i].r)>>1;
    if(p <= mid) update_tree(ls(i), p, x);
    else update_tree(rs(i), p, x);
    push_up(i);
}

llpair query_tree(int i, int l, int r)
{
    if(tr[i].l >= l && tr[i].r <= r) return make_pair(tr[i].v1, tr[i].v2);
    int mid = (tr[i].l+tr[i].r)>>1;
    llpair lp, rp;
    lp.first = lp.second = rp.first = rp.second = 0;
    if(l <= mid) lp = query_tree(ls(i), l, r);
    if(r >  mid) rp = query_tree(rs(i), l, r);
    push_up(i);
    return make_pair((lp.first+rp.first)%MOD, (lp.second+rp.second)%MOD);
}

void exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return; }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

inline int mul_inverse(int a)
{
    int x, y;
    exgcd(a, MOD, x, y);
    return (x%MOD+MOD)%MOD;
}
