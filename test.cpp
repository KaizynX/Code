#include <bits/stdc++.h>

using namespace std;

inline long long sum(int l, int r)
{
    int x = l+r, y = r-l+1;
    if(x&1) y /= 2;
    else x /= 2;
    return 1ll*x*y;
}

inline long long calc(int l, int r, int i)
{
    int a = l/i, b = r/i;
    if(a == b) return sum(l%i, r%i);
    long long res = sum(l%i, i-1)+sum(0, r%i);
    if(a+1 > b) res += sum(0, i-1)*(b-a-1);
    return res;
}

inline long long baoli(int l, int r, int i)
{
    long long res = 0;
    for(int j = l; j <= r; ++j)
        res += j%i;
    return res;
}

int main()
{
    for(int i = 1; i <= 100; ++i)
    {
        for(int j = i; j <= 100; ++j)
        {
            for(int k = 1; k <= i; ++k)
                printf("%d %d %d:%lld %lld\n", i, j, k, baoli(i,j,k), calc(i,j,k));
        }
    }
	return 0;
}
