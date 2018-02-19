#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//�߾���ѹλ(��֧�ָ���)
struct BigInteger
{
	static const int BASE = 1e5; // % ����һ����λ���� 0 ~ 9999
	static const int WIDTH = 4;  // һ����λ���
	vector<int> v;               // ����Ϊ v.size()
	//���캯�� ��ֵ�����������
	BigInteger( long long num = 0 ) { *this = num; }
	BigInteger( const string &str ) { *this = str; }
	//���ظ�ֵ����� long long �汾
	BigInteger operator = (long long num)
	{
		v.clear();
		//ʹ�� do while ��ֹ num == 0
		do{
			v.push_back(num % BASE);
			num /= BASE;
		}while(num > 0);
		return *this;
	}
	//���ظ�ֵ����� string �汾
	BigInteger operator = (const string &str)
	{
		v.clear();
		/* len ����������ʹ�䱣֤����
		 * strlen  len  (��kΪ����)
		 *  k*B-1   k
		 *  k*B     k
		 *  k*B+1   k               */
		int tmp, len = (str.length() - 1) / WIDTH + 1;
		for(int i(0); i < len; ++i)
		{
			int end = str.length() - i * WIDTH;
			// �浽���λʱ i = len-1
			int start = max(0, end - WIDTH);
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
		if(v.size() != b.v.size())         // �ȱȽϳ���
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
	BigInteger operator + (const BigInteger &b)const
	{
		BigInteger res;
		//res.v.clear();
		for(unsigned i(0), g(0); ; ++i)
		{
			// ����λȫ����,��ӵ���������ÿһλ�������� break
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
	// ֻ��ȷ��*this > b
	BigInteger operator - (const BigInteger &b)const
	{
		BigInteger res = *this;
		// g �Ƿ�����λ��һ��1
		for(unsigned i(0),g(0); i<v.size(); ++i)
		{
			if(i >= b.v.size())break;
			res.v[i] -= b.v[i] + g;
			res.v[i] >= 0 ? g = 0 : ( res.v[i] += BASE, g = 1);
		}
		// ȥ��ĩβ�����0
		while(res.v[res.v.size()-1]==0)res.v.pop_back();
		return res;
	}

	BigInteger operator * (const BigInteger &b)const
	{
		BigInteger res;
		//res.v.clear();
	}
	// ��չ���������
	BigInteger operator += (const BigInteger &b) { *this = *this + b; return *this; }
	BigInteger operator -= (const BigInteger &b) { *this = *this - b; return *this; }
	//BigInteger operator *= (const BigInteger &b) { *this = *this * b; return *this; }
	//BigInteger operator /= (const BigInteger &b) { *this = *this / b; return *this; }
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
	out<< bigint.v.back();                       // ֱ��������λ
	for(int i( bigint.v.size()-2 ); i >= 0; --i) // ���λ�Ѿ����,��-2��ʼ
	{
		char buf[10];                           // ������ʱ���ַ�����
		sprintf(buf, "%04d", bigint.v[i]);      // sprintf �� printf ���뵽 char[] ��
		for(unsigned j = 0; j < strlen(buf); ++j)
			out << buf[j];
	}
	return out;
}

//��һ���������
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
