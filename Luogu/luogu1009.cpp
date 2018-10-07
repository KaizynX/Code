#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int Maxn = 50 + 5;

int n;

struct Big
{
	static const int B = 1e7;
	static const int W = 7;
	vector<int> v;
	Big operator = (int num)
	{
		do{
			v.push_back(num%B);
			num/=B;
		}while(num);
		return *this;
	}

	Big () = default;
	Big (const int num) 
	{
		*this = num;
	}

	Big operator + (Big &b)const
	{
		Big res;
		res.v.clear();
		for(size_t i=0,g=0; ;++i)
		{
			if(g==0 && i >= v.size() && i>=b.v.size())
				break;
			int tmp = g;
			if(i < v.size()) tmp += v[i];
			if(i < b.v.size() ) tmp += b.v[i];
			res.v.push_back( tmp % B );
			g = tmp / B;
		}
		return res;
	}

	Big operator += (Big &b)
	{
		*this = *this + b;
		return *this;
	}
	/*
	Big operator * (int k)const// Wrong
	{
		int g = 0, tmp;
		Big res;
		res.v.clear();
		for(size_t i=0;i<v.size();++i)
		{
			tmp = v[i] * k;
			g = tmp / B;
			res.v.push_back( tmp % B );
		}
		while(g)
		{
			res.v.push_back( g % B );
			g /= B;
		}
		return res;
	}
	*/
	Big operator * (const Big &b)const
	{
		Big res;
		res.v.resize( v.size() + b.v.size() );
		for(size_t i = 0; i < v.size(); ++i )
		{
			for(size_t j = 0; j < b.v.size(); ++j)
			{
				res.v[i+j] += v[i] * b.v[j];
				res.v[i+j+1] += res.v[i+j] / B;
				res.v[i+j] %= B;
			}
		}
		if(res.v.back() ==0 )
			res.v.pop_back();
		return res;
	}

	Big operator *= (int k)
	{
		*this = *this * k;
		return *this;
	}

}tmp,ans;

ostream& operator << (ostream &out,Big &big)
{
	out<<big.v.back();
	for(int i=big.v.size()-2;i>=0;--i)
	{
		char buf[20];
		sprintf(buf,"%07d",big.v[i]);
		for(size_t j=0;j<strlen(buf);++j)
			out<<buf[j];
	}
	return out;
}

int main()
{
	cin>>n;
	tmp = 1;
	ans = 1;
	for(int i=2;i<=n;++i)
	{
		tmp *= i;
		ans += tmp;
	}
	cout << ans << endl;

	return 0;
}
