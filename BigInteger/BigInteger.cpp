#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//�߾���ѹλ
struct BigInteger
{
	static const int BASE = 1e4; // % ����һ����λ���� 0 ~ 9999
	static const int WIDTH = 4;  // һ����λ���

	vector<int> v;
	bool tag = 0 ;                // ����λ 0 +  1 -

	//���캯�� ��ֵ�����������
	BigInteger( long long num = 0 ) { *this = num; }
	BigInteger( const string &str ) { *this = str; }

	//���ظ�ֵ����� long long �汾
	BigInteger operator = (long long num)
	{
		v.clear();
		if(num < 0)
		{
			tag = true;
			num = - num; // ʹ��ת��Ϊ����
		}
		else tag = false;
		//ʹ�� do while ��ֹ num == 0
		do{
			// ������ǿ������ת�� (��Ϊ����ˬWaring)
			v.push_back( static_cast<int>(num % BASE) );
			num /= BASE;
		}while(num > 0);
		return *this;
	}
	//���ظ�ֵ����� string �汾
	BigInteger operator = (const string &former_str)
	{
		string str;
		v.clear();
		if(former_str[0] == '-')
		{
			tag = true;
			str = former_str.substr(1); // ȥ����һλ
		}
		else
		{
			tag = false;
			str = former_str;
		}
		/* len ����������ʹ�䱣֤����
		 * strlen  len  (��kΪ����)
		 *  k*B-1   k
		 *  k*B     k
		 *  k*B+1   k               */
		int tmp, len = (str.length() - 1) / WIDTH + 1, head = 0;
		for(int i = 0; i < len; ++i)
		{
			int end = str.length() - i * WIDTH;
			// �浽���λʱ i = len-1
			int start = max(head, end - WIDTH);
			/* sscanf �� char[] �� scanf
			 * str.substr(start, length) ��str�д�start��ʼ��ȡ����length���ַ���
			 * .c_str �� string ת��Ϊ char[]                                  */
			sscanf( str.substr(start, end-start).c_str(), "%d", &tmp);
			v.push_back(tmp);
		}
		return *this;
	}

	// ���رȽ������
	bool operator < (const BigInteger &b)const
	{
		if(tag != b.tag)                   // �ȽϷ���
			return tag > b.tag;            // 1 > 0 <==> �� < ��
		if(tag && b.tag)                   // �����Ƚ�,����෴
			return ( -b < -*this );

		if(v.size() != b.v.size())         // �Ƚϳ���
			return v.size() < b.v.size();
		for(int i = v.size()-1; i>=0; --i) // �����λ��ʼ��
		{
			if(v[i] != b.v[i])
				return v[i] < b.v[i];
		}
		return false;                      //���
	}

	bool operator >  (const BigInteger &b) const { return b < *this; }
	bool operator <= (const BigInteger &b) const { return !(b < *this); }
	bool operator >= (const BigInteger &b) const { return !(*this < b); }
	bool operator != (const BigInteger &b) const { return b < *this || *this < b; }
	bool operator == (const BigInteger &b) const { return !(b < *this) && !(*this <b); }

	// �������������
	// �߾��� & �;���
	/*
	BigInteger operator * (const int b) const
	{
		BigInteger res;
		res.v.clear();
		return *this * b;
	}

	BigInteger operator / (const int b) const
	{
		return *this / b;
	}

	BigInteger operator % (const int b) const
	{
		return *this % b;
	}
	*/
	// �߾��� & �߾���
	BigInteger operator + (const BigInteger &b) const
	{
		if(  tag && !b.tag ) return ( b - (-*this) ); // �� + �� --> �� - (-��)
		if( !tag &&  b.tag ) return ( *this - (-b) ); // �� + �� --> �� - (-��)
		BigInteger res;
		res.v.clear();
		if(tag && b.tag) res.tag = true;              // �� + ��
		else res.tag = false;
		int g = 0;                                 // gΪ0��1
		// ����Ϊ �� + ��
		for(unsigned i = 0; ; ++i)
		{
			// ����λȫ����,��ӵ���������ÿһλ�������� break
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

	// һԪ - �����
	BigInteger operator - ()const
	{
		BigInteger res(*this);
		res.tag = ! tag; // ����λȡ��
		return res;
	}

	BigInteger operator - (const BigInteger &b)const
	{
		if( !(!tag && !b.tag) ) return ( *this + (-b) ); // ֻҪ���� �� - ��
		BigInteger res;
		res.v.clear();
		// ת��Ϊ �� �� С
		if(*this < b) return -( b - *this );
		// ����Ϊ �� - ��
		res.tag = false;
		int g = 0; // g Ϊ0��-1
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
		// ȥ�����λ��0,��СΪ0
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

		res.tag = tag ^ b.tag; // ^���

		return res;
	}

	BigInteger operator / (const BigInteger &b)const
	{
		BigInteger divisor,dividend(b),res,tmp;             // ���� ������ ���
		divisor.v.clear();
		res.v.clear();
		divisor.tag = false;
		dividend.tag = false;                               // ת��Ϊ��
		bool res_init = false;
		int l, r, mid ,need;
		for(int i = v.size() - 1; i >= 0; --i)          // �����λ��ʼ
		{
			divisor.v.insert(divisor.v.begin(), v[i] ); // ������ǵ�λ,�嵽ǰ��
			if(divisor < dividend) continue;
			// ����
			l = 0; r = BASE - 1, need = -1;
			while(l <= r)
			{
				mid = (l + r) / 2;
				tmp = dividend * mid;
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
			divisor -= dividend * need;
			res.v[i] = need;
			/*  ����,Ч�ʵ���
			while( divisor >= b )
			{
				divisor -= b;
				if(!res_init)                           // res.v��Ҫ��ʼ��
				{
					res.v.resize(i + 1, 0);
					res_init = true;
				}
				res.v[i]++;
			}
			*/
		}
		// if res == 0
		if(!res.v.size()) res = 0;
		res.tag = tag ^ b.tag; // ^���
		return res;
	}

	BigInteger operator %  (const BigInteger &b) const
	{ 
		BigInteger p_a, p_b, res;   // �� this �� b ת��Ϊ��
		p_a = (*this < 0 ? -*this : *this);
		p_b = (b < 0 ? -b : b);
		res = p_a - p_a / p_b * p_b;
		res.tag = tag;              // �����������this��ͬ
		return res;
	}

	// ��չ
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
};

// ���� >> �����
istream& operator >> (istream &in, BigInteger &bigint)
{
	string str;
	if( in >> str )   // �ɹ�����str
		bigint = str; // ���ع��ĸ�ֵ�����
	return in;
}

// ���� << �����
ostream& operator << (ostream &out, BigInteger &bigint)
{
	if(bigint.tag) out << "-" ;                  // ����
	out<< bigint.v.back();                       // ֱ��������λ
	for(int i( bigint.v.size()-2 ); i >= 0; --i) // ���λ�Ѿ����,��-2��ʼ
	{
		char buf[10];                            // ������ʱ���ַ�����
		sprintf(buf, "%04d", bigint.v[i]);       // sprintf �� printf ���뵽 char[] ��
		for(unsigned j = 0; j < strlen(buf); ++j)
			out << buf[j];
	}
	return out;
}

BigInteger abs (const BigInteger &a)
{
	return a < 0 ? -a : a;
}

BigInteger sqrt (const BigInteger &a)
{
	BigInteger l, r(a), mid, power_value;
	// �����Ҵ�
	while(l <= r)
	{
		mid = (l + r) / 2;
		power_value = mid * mid;                  // power_value = mid ^ 2
		if(power_value == a ) return mid;
		else if(power_value < a ) l = mid + 1;
		else r = mid - 1;                         // power_value > *this
	}
	// ����ȡ��return min(l, r)
	return l < r ? l : r;
}

BigInteger pow (const BigInteger &a, const long long k)
{
	if( k == 0 ) return 1;
	if( k == 1 ) return a;
	if( k == 2 ) return a * a;
	if( k %  2 ) return a * pow(a, k - 1);
	return pow( pow(a, k / 2), 2);
}

BigInteger pow (const BigInteger &a, const BigInteger &k)
{
	if( k == 0 ) return 1;
	if( k == 1 ) return a;
	if( k == 2 ) return a * a;
	if( k.v.back() % 2 ) return a * pow(a, k - 1);
	return pow( pow(a, k / 2), 2);
}

int main()
{
	// test
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test.out","w",stdout);
	//
	BigInteger a,b,c;
	cin >> a >> b ;
	c = a + b;
	cout << c << endl;
	c = a - b;
	cout << c << endl;
	c = a * b;
	cout << c << endl;
	c = a / b;
	cout << c << endl;
	c = a % b;
	cout << c << endl;
	return 0;
}
