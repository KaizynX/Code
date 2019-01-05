#include <bits/stdc++.h>

using namespace std;

int n;
int p[1000000];

void p()
{
    // x = pi^ki...
    for(int i = 2; i*i <= x; ++i)
        if(x%i == 0) {
            p[++tot] = i;
            for(; x%i == 0; x /= i) k[tot]++;
        }
    if(x > 1) p[++tot] = x, k[tot] = 1;
}

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
    for(int k = n; k; --k)
    {
        if(n%k) continue;
        int cur = 1+k;
        if(cur > n) cur -= n;
        long long sum = 1;
        while(cur != 1)
        {
            sum += cur;
            cur += k;
            if(cur > n) cur -= n;
        }
        cout << sum << " ";
    }
    return 0;
}
