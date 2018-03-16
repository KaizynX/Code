#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

string n;
int k;
bool change[13][13]; // [0~9][0~9]
int res[13]; // res[i] : the number of kind 'i' can change into
bool vis[13];
queue <int> q;

struct BigInteger
{
	static const int BASE = 1e4; // % 下来一个单位就是 0 ~ 9999
	static const int WIDTH = 4;  // 一个单位宽度

	vector<int> v;
	int tag = 0 ;                // 符号位 0 +  1 -

	//构造函数 赋值运算符被重载
	BigInteger( long long num = 0 ) { *this = num; }
	BigInteger( const string &str ) { *this = str; }

	//重载赋值运算符 long long 版本
	BigInteger operator = (long long num)
	{
		v.clear();
		if(num < 0)
		{
			tag = 1;
			num = - num; // 使它转化为正数
		}
		else tag = 0;
		//使用 do while 防止 num == 0
		do{
			// 如下是强制类型转换 (因为看不爽Waring)
			v.push_back( static_cast<int>(num % BASE) );
			num /= BASE;
		}while(num > 0);
		return *this;
	}
	//重载赋值运算符 string 版本
	BigInteger operator = (const string &former_str)
	{
		string str;
		v.clear();
		if(former_str[0] == '-')
		{
			tag = 1;
			str = former_str.substr(1); // 去掉第一位
		}
		else
		{
			tag = 0;
			str = former_str;
		}
		/* len 的神奇运算使其保证合理
		 * strlen  len  (设k为常数)
		 *  k*B-1   k
		 *  k*B     k
		 *  k*B+1   k               */
		int tmp, len = (str.length() - 1) / WIDTH + 1, head = 0;
		for(int i = 0; i < len; ++i)
		{
			int end = str.length() - i * WIDTH;
			// 存到最高位时 i = len-1
			int start = max(head, end - WIDTH);
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
		if(tag != b.tag)                   // 比较符号
			return tag > b.tag;            // 1 > 0 <==> 负 < 正
		if(tag && b.tag)                   // 负数比较,结果相反
			return ( -b < -*this );

		if(v.size() != b.v.size())         // 比较长度
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
		if(  tag && !b.tag ) return ( b - (-*this) ); // 负 + 正 --> 正 - (-负)
		if( !tag &&  b.tag ) return ( *this - (-b) ); // 正 + 负 --> 正 - (-负)
		BigInteger res;
		res.v.clear();
		if(tag && b.tag) res.tag = 1;              // 负 + 负
		else res.tag = 0;
		int g = 0;                                 // g为0或1
		// 以下为 正 + 正
		for(unsigned i = 0; ; ++i)
		{
			// 当进位全进了,相加的两个数的每一位都加完了 break
			if(g == 0 && i >= v.size() && i >= b.v.size())
				break;
			int tmp = g;
			if(i < v.size()) tmp += v[i];
			if(i < b.v.size()) tmp += b.v[i];
			res.v.push_back( tmp % BASE );
			g = tmp / BASE;
		}
		return res;
	}

	// 一元 - 运算符
	BigInteger operator - ()const
	{
		BigInteger res(*this);
		res.tag = ! tag; // 符号位取反
		return res;
	}

	BigInteger operator - (const BigInteger &b)const
	{
		if( !(!tag && !b.tag) ) return ( *this + (-b) ); // 只要不是 正 - 正
		BigInteger res;
		res.v.clear();
		// 转化为 大 减 小
		if(*this < b) return -( b - *this );
		// 以下为 正 - 正
		res.tag = 0;
		int g = 0; // g 为0或-1
		for(unsigned i = 0; ; ++i)
		{
			if(g == 0 && i >= v.size() && i >= b.v.size())
				break;
			int tmp = g; // tmp -9999 ~ 9999
			if(i < v.size()) tmp += v[i];
			if(i < b.v.size()) tmp -= b.v[i];
			g = (tmp < 0 ? -1 : 0);
			if(tmp < 0) tmp += BASE;
			res.v.push_back( tmp );
		}
		// 去掉最高位的0,最小为0
		while(!res.v.back() && res.v.size()>1)
			res.v.pop_back();
		return res;
	}

	BigInteger operator * (const BigInteger &b)const
	{
		if(*this == 0 || b == 0)return 0;
		BigInteger res;
		res.v.resize( v.size() + b.v.size() , 0);
		for(size_t i = 0; i < v.size(); ++i )
		{
			for(size_t j = 0; j < b.v.size(); ++j)
			{
				res.v[i+j] += v[i] * b.v[j];
				res.v[i+j+1] += res.v[i+j] / BASE;
				res.v[i+j] %= BASE;
			}
		}
		if(res.v.back() ==0 )
			res.v.pop_back();

		res.tag = tag ^ b.tag; // ^异或

		return res;
	}

	BigInteger operator / (const BigInteger &b)const
	{
		BigInteger divisor,dividend(b),res,tmp;             // 除数 被除数 结果
		divisor.v.clear();
		res.v.clear();
		dividend.tag = 0;                               // 转化为正
		bool res_init = false;
		int l, r, mid ,need;
		for(int i = v.size() - 1; i >= 0; --i)          // 从最高位开始
		{
			divisor.v.insert(divisor.v.begin(), v[i] ); // 插入的是低位,插到前面
			if(divisor < b) continue;
			// 二分
			l = 0; r = BASE - 1, need = -1;
			while(l <= r)
			{
				mid = (l + r) / 2;
				tmp = b * mid;
				if(tmp == divisor)
				{
					need = mid;
					break;
				}
				if(tmp < divisor) l = mid + 1;
				else r = mid - 1;
			}
			if(need == -1) need = l < r ? l : r;        // need = min(l, r);
			if(!res_init) 
			{
				res.v.resize(i + 1, 0);
				res_init = true;
			}
			divisor -= b * need;
			res.v[i] = need;
			/*  减法,效率低下
			while( divisor >= b )
			{
				divisor -= b;
				if(!res_init)                           // res.v需要初始化
				{
					res.v.resize(i + 1, 0);
					res_init = true;
				}
				res.v[i]++;
			}
			*/
		}
		res.tag = tag ^ b.tag; // ^异或
		return res;
	}

	BigInteger operator %  (const BigInteger &b) const
	{ 
		BigInteger p_a, p_b, res;   // 把 this 和 b 转化为正
		p_a = (*this < 0 ? -*this : *this);
		p_b = (b < 0 ? -b : b);
		res = p_a - p_a / p_b * p_b;
		res.tag = tag;              // 结果的正负与this相同
		return res;
	}

	// 扩展
	BigInteger operator ++ () { *this += 1; return *this; }
	BigInteger operator -- () { *this -= 1; return *this; }
	BigInteger operator += (const BigInteger &b) { *this = *this + b; return *this; }
	BigInteger operator -= (const BigInteger &b) { *this = *this - b; return *this; }
	BigInteger operator *= (const BigInteger &b) { *this = *this * b; return *this; }
	BigInteger operator /= (const BigInteger &b) { *this = *this / b; return *this; }
	BigInteger operator %= (const BigInteger &b) { *this = *this % b; return *this; }

	/*
	void print ()const
	{
		if(this->tag)putchar('-');
		printf("%d",this->v.back());
		for(int i = this->v.size() - 2; i >= 0; --i)
		{
			printf("%04d",this->v.at(i));
		}
	}
	*/
}ans;

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
	if(bigint.tag) out << "-" ;                  // 负号
	out<< bigint.v.back();                       // 直接输出最高位
	for(int i( bigint.v.size()-2 ); i >= 0; --i) // 最高位已经输出,故-2开始
	{
		char buf[10];                            // 定义临时的字符数组
		sprintf(buf, "%04d", bigint.v[i]);       // sprintf 用 printf 输入到 char[] 中
		for(unsigned j = 0; j < strlen(buf); ++j)
			out << buf[j];
	}
	return out;
}

int main()
{
	int x, y;
	// in
	// memset(change,0,sizeof change);
	cin >> n >> k;
	for(int i = 0; i < k; ++ i)
	{
		cin >> x >> y;
		change[x][y] = true;
	}
	// Initialization
	// memset(res,0,sizeof res);
	for(int i = 0; i <= 9; ++ i)
	{
		memset(vis,0,sizeof vis);
		// q.clear();
		q.push(i);
		vis[i] =true;
		res[i] ++; // no change
		while(!q.empty())
		{
			x = q.front();
			q.pop();
			for(int j = 0; j <= 9; ++ j)
			{
				if(!vis[j] && change[x][j])
				{
					vis[j] = true;
					q.push(j);
					res[i] ++;
				}
			}
		}
	}
	// search
	ans = 1;
	for(char c : n)
	{
		x = c - 48;
		ans *= res[x];
	}
	cout << ans << endl;
	return 0;
}
