#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;

int n = 1e3, a;
int check[Maxn], prime[Maxn], cnt;

inline int ppp(int x)
{
	int tmp = x, res = 0;
	while(tmp)
	{
		res += tmp%10;
		tmp /= 10;
	}
	return res;
}

inline bool pp(int x)
{
	int cal1 = ppp(x), cal2 = 0;
	for(int i = 2; i*i <= x; ++i)
	    for(; x%i == 0; x /= i) cal2 += ppp(i);
	if(x > 1) cal2 += ppp(x);
	return cal1 == cal2;
}

inline void init()
{
    check[1] = true;
    for(int i = 2; i <= n; ++i)
    {
        if(!check[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i*prime[j] <= n; ++j)
        {
            check[ i*prime[j] ] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
	init();
	cin >> a;
	for(int i = 1, num = 0; num < a; ++i)
	{
		if(!check[i]) continue;
		if(pp(i))
		{
			++num;
			cout << i << ",";
		}
	}
	return 0;
}
