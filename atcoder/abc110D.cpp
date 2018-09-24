#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;
const int Maxm = 1e9+7;
const int Mo = 1e9+7;

int n, m;
vector<int> v;

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
    vector<int> x, y;
    for(int i = a; i > a-b; --i)
        x.emplace_back(i);
    for(int i = 2; i <= b; ++i)
        y.emplace_back(i);
    for(int i = 0; i < x.size(); ++i)
        for(int j = y.size()-1; j >= 0; --j)
        {
            if(x[i]%y[j] == 0)
            {
                x[i] /= y[j];
                y[j] = 1;
            }
        }
    long long res = 1;
    for(int i : x)
        res = res*i%Mo;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    // M = a1^b1+a2^b2+...+ai*bi
    // v = { b1, b2 ... bi }
    Prime_factorization(m, v);
    long long ans = 1;
    for(int i : v)
        ans = ans*comb(i+n-1, min(i, n-1))%Mo;
    printf("%lld\n", ans);
    return 0;
}
