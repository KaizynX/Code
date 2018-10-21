#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;

int n, T, m;
int tr[Maxn], ok[Maxn], s[Maxn];
long long a[Maxn];

inline void update_tree(int i, int x)
{
    for( ; i <= n; i += i&-i) tr[i] += x;
}

inline int query_tree(int x, int y)
{
    int resx = 0, resy = 0;
    for(int i = x-1; i; i -= i&-i) resx += tr[i];
    for(int i = y; i; i -= i&-i) resy += tr[i];
    return resy-resx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> T;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(a[i] <= T) ok[i] = 1, update_tree(i, 1);
        else ok[i] = -1;
    }
    cin >> m;
    string str;
    int x, y, now;
    for(int i = 1; i <= m; ++i)
    {
        cin >> str >> x >> y;
        // query
        if(str == "Zero" || str == "Mike")
        {
            if(x > y) swap(x, y);
            cout << 600ll*query_tree(x, y) << endl;
        }
        else
        {
            // change the hard, can change INF
            if(str == "tingtime")
                a[x] = y, s[x] = 0;
            // decrease, can't change INF
            else if(str == "BookCity" && !s[x])
                a[x] = max(a[x]-y, 1ll);
            // multiply
            else if(str == "Guy")
            {
                if(y == 0) a[x] = 1, s[x] = 0;
                else if(!s[x] && y > 1)
                {
                    // if(a[x]*y - 1ll*(m-i)*INT_MAX > T)
                    // the rest time of decrease can't make it <= T
                    if(y > (1ll*(m-i)*INT_MAX+T)/a[x]) s[x] = 1;
                    else a[x] *= y;
                }
            }
            // INF
            if(s[x]) now = -1;
            // now status
            else now = a[x] <= T ? 1 : -1;
            // if statu changed, update the tree
            if(ok[x] != now) update_tree(x, (ok[x]=now));
        }
    }
    return 0;
}
