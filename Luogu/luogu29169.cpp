#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 5e3+7;

int r, n, ans, fa[Maxn];
struct Node
{
    int x, y;
    bool operator < (const Node &b) const
    {
        return x < b.x;
    }
} a[Maxn];

inline double dis(int i, int j)
{
    return sqrt((long long)(a[i].x-a[j].x)*(a[i].x-a[j].x) + (long long)(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

int getf(int s)
{
    return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

inline bool co(int i, int j)
{
    int fi = getf(i), fj = getf(j);
    if(fi == fj) return false;
    fa[fi] = fj;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        fa[i] = i;
    }
    ans = n; r <<= 1;
    sort(a+1, a+n+1);
    for(int i = 1; i < n; ++i)
        for(int j = i+1; j <= n && a[j].x-a[i].x <= r; ++j)
            if(dis(i, j) <= r)
                if(co(i, j)) --ans;
    cout << ans << endl;
    return 0;
}
