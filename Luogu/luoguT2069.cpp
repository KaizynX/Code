#include <bits/stdc++.h>

using namespace std;

long long n, ans = 1;

inline bool is_prime(long long x)
{
    if(x == 1) return false;
    if(x == 2 || x == 3) return true;
    if(x%6 != 1 && x%6 != 5) return false;
    for(long long i = 5; i*i <= x; i += 6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}

int main()
{
    cin >> n;
    if(is_prime(n)) return puts("3")&0;

    if((n&1) == 0)
    {
        int cnt = 0;
        for(; (n&1) == 0; n >>= 1, ++cnt);
        ans *= cnt*2+1;
    }
    for(long long i = 3; i <= n; i += 2)
        if(n%i == 0)
        {
            int cnt = 0;
            for(; n%i == 0; n /= i, ++cnt);
            ans *= cnt*2+1;
            if(is_prime(n))
            {
                ans *= cnt*2+1;
                break;
            }
        }
    cout << ans << endl;
    return 0;
}
