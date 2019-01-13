#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, q;
int a[Maxn];
long long s[Maxn], ss[Maxn];

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[i] = (i-2 > 0 ? s[i-2] : 0)+a[i];
        ss[i] = ss[i-1]+a[i];
    }

    for(int i = 1, x; i <= q; ++i)
    {
        cin >> x;
        if(x >= a[n-1])
        {
            cout << s[n] << endl;
            continue;
        }
        int l = 0, r = a[n]-x, pl, pr;
        while(l < r)
        {
            int mid = (l+r+1)>>1;
            pl = lower_bound(a+1, a+n, x-mid)-a;
            pr = upper_bound(a+1, a+n, x+mid)-a;
            if(pr-pl > n-pr+1) r = mid-1;
            else l = mid;
            /*
            else if(pr-pl < n-pr) l = mid+1;
            else l = mid; // (n-pr+1)-1 <= (pr-pl) <= (n-pr+1)
            */
        }
        pl = lower_bound(a+1, a+n, x-l)-a;
        pr = upper_bound(a+1, a+n, x+l)-a;
        if(n-pr == pr-pl) cout << (ss[n]-ss[pr-1])+(pl-2 > 0 ? s[pl-2] : 0) << endl;
        else if(pr-pl == n-pr+1) cout << (ss[n]-ss[pr-1])+(pl-1 > 0 ? s[pl-1] : 0) << endl;
        else if(pr-pl == n-pr-1)
        {
            // choose pr
            if(pl-1 < 1 || x-a[pl-1] > a[pr]-x)
                cout << (ss[n]-ss[pr])+(pl-1 > 0 ? s[pl-1] : 0) << endl;
            else // choose pl
                cout << (ss[n]-ss[pr-1])+(pl-3 > 0 ? s[pl-3] : 0) << endl;
        }
    }
    return 0;
}
