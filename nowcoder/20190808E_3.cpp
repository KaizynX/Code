#include <bits/stdc++.h>

using namespace std;

const int Maxn = 4e5+7;

int n, a1, a2, b1, b2, c1, c2, m1, m2;
int x[3], y[3];
int arr[Maxn<<1], cnt = 0;
int rnl[Maxn<<2], rnr[Maxn<<2];
int tradd[Maxn<<4];
long long trsum[Maxn<<4];

inline int ls(int i) { return i<<1; }
inline int rs(int i) { return i<<1|1; }
inline void push_up(int i) { trsum[i] = trsum[ls(i)]+trsum[rs(i)]; }

inline void push_down(int i, int l, int r)
{
    if(!tradd[i]) return;
    int mid = (l+r)>>1;
    trsum[ls(i)] += 1ll*tradd[i]*(rnr[mid]-rnl[l]+1);
    trsum[rs(i)] += 1ll*tradd[i]*(rnr[r]-rnl[mid+1]+1);
    tradd[ls(i)] += tradd[i];
    tradd[rs(i)] += tradd[i];
    tradd[i] = 0;
}

inline void update_tree(int i, int _x, int _y, int l, int r)
{
    if(_x <= rnl[l] && _y >= rnr[r])
    {
        trsum[i] += rnr[r]-rnl[l]+1;
        tradd[i]++;
        return;
    }
    push_down(i, l, r);
    int mid = (l+r)>>1;
    if(_x <= rnr[mid])  update_tree(ls(i), _x, _y, l, mid);
    if(_y >= rnl[mid+1]) update_tree(rs(i), _x, _y, mid+1, r);
    push_up(i);
}

inline int query_tree(int i, long long need, int l, int r)
{
    if(l == r)
    {
        long long per = trsum[i]/(rnr[r]-rnl[l]+1);
        return rnl[l]+int((need-1)/per);
    }
    push_down(i, l, r);
    int mid = (l+r)>>1;
    if(trsum[ls(i)] < need) return query_tree(rs(i), need-trsum[ls(i)], mid+1, r);
    else return query_tree(ls(i), need, l, mid);
}

int main()
{
    int l, r, x_1, x_2, y_1, y_2;
    cin >> n;
    cin >> x_1 >> x_2 >> a1 >> b1 >> c1 >> m1;
    cin >> y_1 >> y_2 >> a2 >> b2 >> c2 >> m2;
    x[1] = x_1; x[2] = x_2;
    y[1] = y_1; y[2] = y_2;
    for(int i = 1; i <= n; ++i)
    {
        if(i > 2)
        {
            x[i%3] = int( (1ll*a1*x[(i-1)%3]+1ll*b1*x[(i-2)%3]+c1)%m1 );
            y[i%3] = int( (1ll*a2*y[(i-1)%3]+1ll*b2*y[(i-2)%3]+c2)%m2 );
        }
        l = min(x[i%3], y[i%3]); // the 1 will be added later
        r = max(x[i%3], y[i%3]);
        arr[i*2-1] = l; arr[i*2] = r;
    }
    // 离散化
    sort(arr+1, arr+n*2+1);
    ++cnt;
    rnl[cnt] = rnr[cnt] = arr[1];
    for(int i = 2; i <= n*2; ++i)
    {
        // 去重
        if(arr[i] == arr[i-1]) continue;
        if(arr[i] != rnr[cnt]+1)
        {
            ++cnt;
            rnl[cnt] = rnr[cnt-1]+1;
            rnr[cnt] = arr[i]-1;
        }
        ++cnt;
        rnl[cnt] = rnr[cnt] = arr[i];
    }
    // 只有一个值
    if(cnt == 1)
    {
        for(int i = 1; i <= n; ++i)
            cout << arr[1]+1 << endl;
        return 0;
    }
    // 线段树
    x[1] = x_1; x[2] = x_2;
    y[1] = y_1; y[2] = y_2;
    for(int i = 1; i <= n; ++i)
    {
        if(i > 2)
        {
            x[i%3] = int( (1ll*a1*x[(i-1)%3]+1ll*b1*x[(i-2)%3]+c1)%m1 );
            y[i%3] = int( (1ll*a2*y[(i-1)%3]+1ll*b2*y[(i-2)%3]+c2)%m2 );
        }
        l = min(x[i%3], y[i%3]); // the 1 will be added later
        r = max(x[i%3], y[i%3]);
        update_tree(1, l, r, 1, cnt);
        cout << query_tree(1, (trsum[1]+1)>>1, 1, cnt)+1 << endl;
    }
    return 0;
}
