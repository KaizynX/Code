#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 1e5+7;

int Q, a;
char s[Maxn];

struct Num
{
	long double v; // v (0, 1]
	long long weishu;
	Num(){ v = 0; weishu = 1; }
	Num(int num) { *this = num; }

	inline void f() { while(v > 10) v /= 10, weishu++; }

	Num operator = (int num)
	{
		v = num;
		weishu = 1;
		this->f();
		return *this;
	}

	Num operator * (const Num &b) const
	{
		Num res;
		res.weishu = weishu+b.weishu-1;
		res.v = v*b.v;
		res.f();
		return res;
	}

	Num operator *= (const Num &b) { return *this = *this*b; }
};

inline Num qpow(Num b, long long p)
{
	Num res = 1;
	while(p)
	{
		if(p&1) res *= b;
		p >>= 1;
		b *= b;
	}
	return res;
}

int main()
{
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d", &a);
		scanf("%s", s);
		Num cur = qpow(a, 1ll*(1+a)*a/2);
#ifdef DEBUG
		cout << cur.v << " " << cur.weishu << endl;
#endif
		for(int i = 0; i <= a; ++i)
		{
			cur *= (s[i]-'0');
#ifdef DEBUG
			cout << cur.v << " " << cur.weishu << endl;
#endif
		}
		printf("%lld\n", cur.weishu);
	}
	return 0;
}
