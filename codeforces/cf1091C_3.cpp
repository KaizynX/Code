#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;

int n;
int a[Maxn], p[Maxn], tot; // a^p
set<int> s;
//typedef set<int>::iterator sit;

inline bool is_prime(long long x)
{
    if(x == 1) return false;
    if(x == 2 || x == 3) return true;
    if(x%6 != 1 && x%6 != 5) return false;
    for(long long i = 5; i*i <= x; i += 6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}

void ppp(int n)
{
    if((n&1) == 0)
    {
        a[++tot] = 2;
        for(; (n&1) == 0; n >>= 1, ++p[tot]);
    }
    for(int i = 3; i <= n; i += 2)
        if(n%i == 0)
        {
            a[++tot] = i;
            for(; n%i == 0; n /= i, ++p[tot]);
            if(is_prime(n))
            {
                a[++tot] = n;
                ++p[tot];
                break;
            }
        }

    s.insert(1);
    for(int i = 1; i <= tot; ++i)
        for(int j = 1; j <= p[i]; ++j)
        {
            //sit ccc = s.end();
            //for(sit it = s.begin(); it != ccc; ++it)
            //    s.insert(*it*a[i]);
            set<int>::iterator ccc = s.end();
        }
}

int main()
{
    cin >> n;
    ppp(n);
    /*
    for(int i = cnt; i; --i)
    {
        int num = (n-1)/v[i];
        long long sum = 1ll*(2+num*v[i])*(num+1)/2;
        cout << sum << " ";
    }
    */
    for(sit it = s.rbegin(); it != s.rend(); --it)
    {
        int num = (n-1)/ *it;
        long long sum = 1ll*(2+num* *it)*(num+1)/2;
        cout << sum << " ";
    }
    return 0;
}
