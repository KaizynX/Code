#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100;

long long k, L, s, w;
int p, ans, a[Maxn];

void brute(int cur)
{
	if(cur > L)
	{
		ans++;
		if(ans >= p) ans -= p; // MOD
#ifdef DEBUG
		for(int i = 1; i <= L; ++i)
			printf("%d ", a[i]);
		putchar('\n');
#endif
		return;
	}

	if(cur == s) brute(cur+1);
	else
	{
		for(int i = 1; i <= k; ++i)
		{
			if((cur > 2 && i == a[cur-2])
			|| (cur > 1 && i == a[cur-1])
			|| (s == cur+1 && i == a[s])
			|| (s == cur+2 && i == a[s]))
				continue;
			a[cur] = i;
			brute(cur+1);
		}
	}
}

inline long long qpow(long long a, long long x)
{
	long long res = 1;
	while(x)
	{
		if(x&1) res = res*a%p;
		x >>= 1;
		a = a*a%p;
	}
	return res;
}

inline void special()
{
	if(L == 1) { ans = (int)(k%p); return; }
	long long a = k%p, res = a*(a-1+p)%p;
	res = res*qpow((a-2+p)%p, L-2)%p;
	ans = (int)res;
}

int main()
{
	cin >> k >> L >> p;
	cin >> s;
	if(s)
	{
		cin >> w;
		a[s] = (int)w;
		brute(1);
		cout << ans << endl;
	}
	/*
	else
	{
		special();
		cout << ans << endl;
	}
	*/
	return 0;
}
