#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 1e5+7;

long long n, k;
int m;
long long p[Maxn];

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) cin >> p[i];
    int l = 0, res = 0;
    long long r = p[0]%k ? p[0]/k*k+k : p[0];
    while(l < m)
    {
        res++;
        if(r < p[l]) r += (p[l]-r)%k ? (p[l]-r)/k*k+k : p[l]-r;
        int pos = upper_bound(p+l, p+m, r)-p;
        r += pos-l;
        l = pos;
#ifdef DEBUG
        cout << l << " " << r << endl;
#endif
    }
    cout << res << endl;
    return 0;
}
