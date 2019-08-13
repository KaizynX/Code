#include <bits/stdc++.h>

using namespace std;

int T;
long long x, z, yy, gg, ggg, tmp;

inline long long gcd(long long a, long long b)
{
    return b ? gcd(b, a%b) : a;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld%lld", &x, &z);
        yy = z/x;
        gg = gcd(x, yy);
        if(gg == 1) printf("%lld\n", yy);
        // if gg -> x
        else if(gcd(x/gg, gg) == 1) printf("%lld\n", yy*gg);
        // if gg -> yy
        else 
        {
            // while(x%(tmp*ggg) == 0) tmp *= ggg;
            x /= gg;
            ggg = gcd(x, gg);
            x /= ggg;
            tmp = gg*ggg;
            while(x%ggg == 0) x /= ggg, tmp *= ggg;
            printf("%lld\n", yy*tmp);
        }
    }
    return 0;
}
