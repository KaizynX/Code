#include <bits/stdc++.h>

using namespace std;

long long n, ans = 1;

inline bool is_prime(long long x)
{
    if(x == 1) return false;
    for(long long i = 2; i*i <= x; ++i)
        if(x%i == 0) return false;
    return true;
}

int main()
{
    cin >> n;
    if(is_prime(n)) return puts("3")&0;
    for(long long i = 2; i <= n; ++i)
    {
        if(n%i == 0)
        {
            int cnt = 0;
            while(n%i == 0)
            {
                n /= i;
                cnt++;
            }
            ans *= cnt*2+1;
            if(is_prime(n))
            {
                ans *= 3;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
