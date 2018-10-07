#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

int x[2], y[2], z[2];
long long _x[2], _y[2], _z[2], ansx, ansy, ansz;

template <typename T> T abs(T x)
{
	return x < 0 ? -x : x;
}

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}

struct Fenshu
{
	long long a, b;
	int tag;

	Fenshu(long long x = 0, long long y = 1)
	{
		a = abs(x);
		b = y;
		tag = x < 0 ? 1 : 0;
	}

	inline void tongfen()
	{
		long long _gcd = gcd(abs(a), abs(b));
		a /= _gcd;
		b /= _gcd;
		if((a<0)^(b<0)) tag = 1;
		a = abs(a);
		b = abs(b);
	}

	Fenshu operator + (const Fenshu &c) const
	{
		Fenshu res;
		res.b = b*c.b;
		res.a = (tag ? -1 : 1)*a*c.b+(c.tag ? -1 : 1)*c.a*b;
		res.tongfen();
		return res;
	}

	Fenshu operator - () const
	{
		Fenshu res(*this);
		res.tag = tag^1;
		return res;
	}

	Fenshu operator - (const Fenshu &c) const
	{
		return *this+(-c);
	}

	Fenshu operator * (const Fenshu &c) const
	{
		Fenshu res;
		res.a = a*c.a*(tag^c.tag ? -1 : 1);
		res.b = b*c.b;
		res.tongfen();
		return res;
	}

	Fenshu operator / (const Fenshu &c) const
	{
		return *this*Fenshu(c.b, c.a);
	}

} resx, resy, resz;

int main()
{
	while(scanf("%d%d%d%d%d%d", x, y, z, x+1, y+1, z+1) == 6)
	{
		// delete x
		int _gcd = gcd(abs(x[0]), abs(x[1]));
		x[0] /= _gcd; x[1] /= _gcd;
		_y[0] = y[0]*x[1]; _z[0] = z[0]*x[1];
		_y[1] = y[1]*x[0]; _z[1] = z[1]*x[0];
		// _y[0]*Y + _z[0]*Z = 0
		_y[0] -= _y[1]; _z[0] -= _z[1];
		if(_y[0] == 0) resz = 0, resy = 1;
		if(_z[0] == 0) resy = 0, resz = 1;
		else
		{
			resy = 1;
			// -(_y[0]/_z[0])*Y = Z
			resz = Fenshu(-1*_y[0])/_z[0];
		}
		// x[0]*X+y[0]*Y+z[0]*Z = 0
		resx = -(resy*y[0]+resz*z[0])/x[0];
		long long tmp = resz.b*resx.b;
		ansx = resx.a*tmp/resx.b*(resx.tag ? -1 : 1);
		ansy = resy.a*tmp/resy.b*(resy.tag ? -1 : 1);
		ansz = resz.a*tmp/resz.b*(resz.tag ? -1 : 1);
		tmp = gcd(abs(ansx), gcd(abs(ansy), abs(ansz)));
		ansx /= tmp;
		ansy /= tmp;
		ansz /= tmp;
		printf("%lld %lld %lld\n", ansx, ansy, ansz);
	}
	return 0;
}
