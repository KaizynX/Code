#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;

struct Node
{
    int s, t;
    bool operator < (const Node &b) const
    {
        return s < b.s;
    }
} a[Maxn];

int main()
{
    while(cin >> n)
    {
        for(int i = 1; i <= n; ++i) cin >> a[i].s;
        for(int i = 1; i <= n; ++i) cin >> a[i].t;
        sort(a+1, a+n+1);
        int cnt = 0, last = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(a[i].s > last)
            {
                cnt++;
                last = a[i].t;
            }
            else last = min(last, a[i].t);
        }
        cout << cnt << endl;
    }
    return 0;
}
