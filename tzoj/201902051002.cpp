#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;

int a, b, c, n;
//int p[Maxn], k[Maxn], tot;
int check[Maxn], prime[Maxn], cnt;

inline void init(int N)
{
    check[1] = true;
    for(int i = 2; i <= N; ++i)
    {
        if(!check[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i*prime[j] <= N; ++j)
        {
            check[ i*prime[j] ] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
    init(1000000);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        // gcd(a, c) == b
        cin >> a >> b;
        a /= b;
        for(int j = 1; j <= cnt; ++j)
            if(a%prime[j])
            {
                c = prime[j];
                break;
            }
        cout << c*b << endl;
    }
    return 0;
}