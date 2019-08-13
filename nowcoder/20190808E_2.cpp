#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 4e5+7;

int n, a1, a2, b1, b2, c1, c2, m1, m2;
int x[3], y[3], l[Maxn], r[Maxn];
int arr[Maxn<<1], cnt = 0;
pair<int, int> rn[Maxn<<2];

struct Tree
{
    // [ rn[l].first, rn[r].second ]
    int l, r;
    long long sum, add;
    Tree(int _l = 0, int _r = 0, int _sum = 0, int _add = 0) : l(_l), r(_r), sum(_sum), add(_add) {}
} tr[Maxn<<4];

inline int ls(int i) { return i<<1; }
inline int rs(int i) { return i<<1|1; }
inline void push_up(int i) { tr[i].sum = tr[ls(i)].sum+tr[rs(i)].sum; }

inline void push_down(int i)
{
    if(!tr[i].add) return;
    tr[ls(i)].sum += tr[i].add*(rn[tr[ls(i)].r].second-rn[tr[ls(i)].l].first+1);
    tr[rs(i)].sum += tr[i].add*(rn[tr[rs(i)].r].second-rn[tr[rs(i)].l].first+1);
    tr[ls(i)].add += tr[i].add;
    tr[rs(i)].add += tr[i].add;
    tr[i].add = 0;
}

void build_tree(int i, int l, int r)
{
    tr[i].l = l; tr[i].r = r;
    if(l == r) return;
    int mid = (l+r)>>1;
    build_tree(ls(i), l, mid);
    build_tree(rs(i), mid+1, r);
}

inline void update_tree(int i, int _x, int _y)
{
    if(_x <= rn[tr[i].l].first && _y >= rn[tr[i].r].second)
    {
        tr[i].sum += rn[tr[i].r].second-rn[tr[i].l].first+1;
        tr[i].add++;
        return;
    }
    push_down(i);
    if(_x <= rn[tr[ls(i)].r].second) update_tree(ls(i), _x, _y);
    if(_y >= rn[tr[rs(i)].l].first)  update_tree(rs(i), _x, _y);
    push_up(i);
}

inline int query_tree(int i, long long need)
{
    if(tr[i].l == tr[i].r)
    {
        long long per = tr[i].sum/(rn[tr[i].r].second-rn[tr[i].l].first+1);
        return rn[tr[i].l].first+int((need-1)/per);
    }
    push_down(i);
    if(tr[ls(i)].sum < need) return query_tree(rs(i), need-tr[ls(i)].sum);
    else return query_tree(ls(i), need);
}

int main()
{
    cin >> n;
    cin >> x[1] >> x[2] >> a1 >> b1 >> c1 >> m1;
    cin >> y[1] >> y[2] >> a2 >> b2 >> c2 >> m2;
    l[1] = min(x[1], y[1]); l[2] = min(x[2], y[2]);
    r[1] = max(x[1], y[1]); r[2] = max(x[2], y[2]);
    arr[1] = l[1]; arr[2] = r[1]; arr[3] = l[2]; arr[4] = r[2];
    for(int i = 3; i <= n; ++i)
    {
        x[i%3] = int( (1ll*a1*x[(i-1)%3]+1ll*b1*x[(i-2)%3]+c1)%m1 );
        y[i%3] = int( (1ll*a2*y[(i-1)%3]+1ll*b2*y[(i-2)%3]+c2)%m2 );
        l[i] = min(x[i%3], y[i%3]); // the 1 will be added later
        r[i] = max(x[i%3], y[i%3]);
        arr[i*2-1] = l[i]; arr[i*2] = r[i];
    }
    // 离散化
    sort(arr+1, arr+n*2+1);
    rn[++cnt] = make_pair(arr[1], arr[1]);
    for(int i = 2; i <= n*2; ++i)
    {
        // 去重
        if(arr[i] == arr[i-1]) continue;
        if(arr[i] != rn[cnt].second+1)
        {
            rn[cnt+1] = make_pair(rn[cnt].second+1, arr[i]-1);
            ++cnt;
        }
        rn[++cnt] = make_pair(arr[i], arr[i]);
    }
    // 只有一个值
    if(cnt == 1)
    {
        for(int i = 1; i <= n; ++i)
            cout << arr[1]+1 << endl;
        return 0;
    }
    // 线段树
    build_tree(1, 1, cnt);
    for(int i = 1; i <= n; ++i)
    {
        update_tree(1, l[i], r[i]);
        cout << query_tree(1, (tr[1].sum+1)>>1)+1 << endl;
    }
    return 0;
}
