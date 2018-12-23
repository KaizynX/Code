#include <bits/stdc++.h>

using namespace std;

long long n, p;

inline bool is_prime(long long x)
{
    if(x == 1) return false;
    if(x == 2 || x == 3) return true;
    if(n%6 != 1 && n%6 != 5) return false;
    for(long long i = 5; i*i <= n; i += 6)
        if(n%i == 0 || n%(i+2) == 0) return false;
    return true;
}

int main()
{
    cin >> n >> p;
    if(n == 1) return printf("%lld\n", p)&0;
    if(is_prime(p)) return puts("1")&0;
    long long ans = 1;
    for(long long i = 2, cnt; i*i <= p; ++i)
    {
        cnt = 0;
        for(; p%i == 0; p /= i, ++cnt);
        for(int j = 1; j <= cnt/n; ++j) ans *= i;
        if(is_prime(p)) break;
    }
    cout << ans << endl;
    return 0;
}
