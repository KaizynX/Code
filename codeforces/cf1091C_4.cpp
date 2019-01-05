#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;

int n;
int a[Maxn], p[Maxn], tot; // a^p
vector<int> v;

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
    for(int i = 2; i <= n; ++i)
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
}

void dfs(int cur, int now)
{
    if(cur > tot)
    {
        v.push_back(now);
        return;
    }
    for(int i = 0; i <= p[cur]; ++i)
    {
        dfs(cur+1, now);
        now *= a[cur];
    }
}

int main()
{
    cin >> n;
    ppp(n);
    dfs(1, 1);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i)
    {
        int num = (n-1)/v[i];
        long long sum = 1ll*(2+num*v[i])*(num+1)/2;
        cout << sum << " ";
    }
    return 0;
}
