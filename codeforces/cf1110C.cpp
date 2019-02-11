#include <bits/stdc++.h>

using namespace std;

int q;
long long a;

bool is_prime(long long x)
{
    for(long long i = 2; i <= sqrt(x); ++i)
        if(x%i == 0) return false;
    return true;
}

int main()
{
    cin >> q;
    int k = 0;
    while(q--)
    {
        cin >> a;
        int num1 = __builtin_popcount(a), num = 0;
        for(long long tmp = a; tmp; tmp >>= 1, num++);
        if(num1 < num) cout << (1ll<<num)-1 << endl;
        else
        {
            if(is_prime(a))
            {
                cout << 1 << endl;
                continue;
            }
            for(long long i = 2; i*i <= a; ++i)
                if(a%i == 0)
                {
                    cout << a/i << endl;
                    break;
                }
        }
    }
    return 0;
}