#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;
const int Maxa = 1e9+7;
const int P1 = 1e9+7;
const int P2 = 1e9+9;

int n, l = 1, r, maxa;
int a[Maxn];

inline long long qpow(long long a, int p, int mo)
{
    long long res = 1;
    for( ; p; p >>= 1, a = a*a%mo)
        if(p&1) res = res*a%mo;
    return res;
}

inline bool check(int m) // m½øÖÆ
{
    long long now1 = 0, now2 = 0;
    for(int i = 2; i <= n; ++i)
    {
        if(a[i] > a[i-1])
        {
            now1 = now1*qpow(m, a[i]-a[i-1], P1)%P1;
        }
        else
        {
            now1 = now1/qpow(m, a[i-1]-a[i], P1)%P1;
            now1 = (now+1)%P1;
            if(now == qpow(m, a[i]+1, P1)) return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    r = n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        r = max(r, a[i]);
        maxa = max(maxa, a[i]);
    }
    while(l < r)
    {
        int mid = (l+r)>>1;
        if(check(mid)) l = r;
        else l = mid+1;
    }
    cout << l << endl;
    return 0;
}
