#include <bits/stdc++.h>

using namespace std;

long long n, b;
long long p[100000];
int k[100000], tot;

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
    cin >> n >> b;
    // x = pi^ki...
    if(is_prime(b))
    {
        p[++tot] = b;
        k[tot] = 1;
        b = 1;
    }
    for(long long i = 2; i*i <= b; ++i)
        if(b%i == 0) {
            p[++tot] = i;
            for(; b%i == 0; b /= i) k[tot]++;
            if(is_prime(b))
            {
                p[++tot] = b;
                k[tot] = 1;
                break;
            }
        }
    if(b > 1) p[++tot] = b, k[tot] = 1;

    long long ans = -1;
    for(int i = 1; i <= tot; ++i)
    {
        long long tmp = n, cur = 0;
        while(tmp)
        {
            cur += tmp/p[i];
            tmp /= p[i];
        }
        if(ans == -1) ans = cur/k[i];
        else ans = min(ans, cur/k[i]);
    }
    cout << ans << endl;
    return 0;
}