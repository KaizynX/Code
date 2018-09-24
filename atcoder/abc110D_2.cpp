#include <bits/stdc++.h>

using namespace std;

const int Mo = 1e9+7;

int n, m;
vector<int> v;

inline long long quickm(long long a, int p) // a^p%Mo
{
    long long res = 1;
    while(p)
    {
        if(p&1) res = res*a%Mo;
        a = a*a%Mo;
        p >>= 1;
    }
    return res;
}

inline long long mul_inverse(long long x)
{
    return quickm(x, Mo-2);
}

inline void Prime_factorization(int x, vector<int> &v)
{
    for(int i = 2, cnt; i <= x; ++i)
    {
        if(x%i) continue;
        cnt = 0;
        while(x%i == 0)
        {
            x /= i;
            cnt++;
        }
        v.emplace_back(cnt);
    }
    if(x > 1) v.emplace_back(x);
}

inline long long comb(int a, int b) // C_a^b
{
    if(b == 0) return 1;
    long long p = 1, q = 1;
    for(int i = 1; i <= b; ++i)
    {
        p = p*a%Mo; a--;
        q = q*i%Mo;
    }
    return p*mul_inverse(q)%Mo;
}

int main()
{
    cin >> n >> m;
    Prime_factorization(m, v);
    long long ans = 1;
    for(int i : v)
        ans = ans*comb(i+n-1, min(i, n-1))%Mo;
    cout << ans << endl;
    return 0;
}
