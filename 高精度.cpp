#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//高精度压位(不支持负数)
struct BigInteger
{
	static const int BASE = 1e5; // % 下来一个单位就是 0 ~ 9999
	static const int WIDTH = 4;  // 一个单位宽度
	vector<int> v;               // 长度为 v.size()
	//构造函数 赋值运算符被重载
	BigInteger( long long num = 0 ) { *this = num; }
	BigInteger( const string &str ) { *this = str; }
	//重载赋值运算符 long long 版本
	BigInteger operator = (long long num)
	{
		v.clear();
		//使用 do while 防止 num == 0
		do{
			v.push_back(num % BASE);
			num /= BASE;
		}while(num > 0);
		return *this;
	}
	//重载赋值运算符 string 版本
	BigInteger operator = (const string &str)
	{
		v.clear();
		/* len 的神奇运算使其保证合理
		 * strlen  len  (设k为常数)
		 *  k*B-1   k
		 *  k*B     k
		 *  k*B+1   k               */
		int tmp, len = (str.length() - 1) / WIDTH + 1;
		for(int i(0); i < len; ++i)
		{
			int end = str.length() - i * WIDTH;
			// 存到最高位时 i = len-1
			int start = max(0, end - WIDTH);
			/* sscanf 从 char[] 中 scanf
			 * str.substr(start, length) 在str中从start开始截取长度length的字符串
			 * .c_str 将 string 转化为 char[]                                  */
			sscanf( str.substr(start, end-start).c_str(), "%d", &tmp);
			v.push_back(tmp);
		}
		return *this;
	}
	// 重载比较运算符
	bool operator < (const BigInteger &b)const
	{
		if(v.size() != b.v.size())         // 先比较长度
			return v.size() < b.v.size();
		for(int i = v.size()-1; i>=0; --i) // 从最高位开始比
		{
			if(v[i] != b.v[i])
				return v[i] < b.v[i];
		}
		return false;                      //相等
	}

	bool operator >  (const BigInteger &b) const { return b < *this; }
	bool operator <= (const BigInteger &b) const { return !(b < *this); }
	bool operator >= (const BigInteger &b) const { return !(*this < b); }
	bool operator != (const BigInteger &b) const { return b < *this || *this < b; }
	bool operator == (const BigInteger &b) const { return !(b < *this) && !(*this <b); }
	// 重载四则运算符
	BigInteger operator + (const BigInteger &b)const
	{
		BigInteger res;
		//res.v.clear();
		for(unsigned i(0), g(0); ; ++i)
		{
			// 当进位全进了,相加的两个数的每一位都加完了 break
			if(g == 0 && i >= v.size() && i >= b.v.size())
				break;
			int tmp(g);
			if(i < v.size()) tmp += v[i];
			if(i < b.v.size()) tmp += b.v[i];
			res.v.push_back( tmp % BASE );
			g = tmp / BASE;
		}
		return res;
	}
	// 只能确保*this > b
	BigInteger operator - (const BigInteger &b)const
	{
		BigInteger res = *this;
		// g 是否该向高位借一个1
		for(unsigned i(0),g(0); i<v.size(); ++i)
		{
			if(i >= b.v.size())break;
			res.v[i] -= b.v[i] + g;
			res.v[i] >= 0 ? g = 0 : ( res.v[i] += BASE, g = 1);
		}
		// 去掉末尾多余的0
		while(res.v[res.v.size()-1]==0)res.v.pop_back();
		return res;
	}

	BigInteger operator * (const BigInteger &b)const
	{
		BigInteger res;
		//res.v.clear();
	}
	// 扩展四则运算符
	BigInteger operator += (const BigInteger &b) { *this = *this + b; return *this; }
	BigInteger operator -= (const BigInteger &b) { *this = *this - b; return *this; }
	//BigInteger operator *= (const BigInteger &b) { *this = *this * b; return *this; }
	//BigInteger operator /= (const BigInteger &b) { *this = *this / b; return *this; }
};

// 重载 >> 运算符
istream& operator >> (istream &in, BigInteger &bigint)
{
	string str;
	if( in >> str )   // 成功读入str
		bigint = str; // 重载过的赋值运算符
	return in;
}

// 重载 << 运算符
ostream& operator << (ostream &out, BigInteger &bigint)
{
	out<< bigint.v.back();                       // 直接输出最高位
	for(int i( bigint.v.size()-2 ); i >= 0; --i) // 最高位已经输出,故-2开始
	{
		char buf[10];                           // 定义临时的字符数组
		sprintf(buf, "%04d", bigint.v[i]);      // sprintf 用 printf 输入到 char[] 中
		for(unsigned j = 0; j < strlen(buf); ++j)
			out << buf[j];
	}
	return out;
}

//另一种输出函数
void print(const BigInteger &bigint)
{
	printf("%d",bigint.v.back());
	for(int i( bigint.v.size()-2 ); i >= 0; ++i)
		printf("%04d",bigint.v[i]);
}

int main()
{
	BigInteger a, b, c;
	cin >> a >> b;
	c = a - b;
	cout << c <<endl;
	return 0;
}
