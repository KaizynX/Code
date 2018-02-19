#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//�߾���ѹλ
struct BigInteger
{
	static const int BASE = 1e5; // % ����һ����λ���� 0 ~ 9999
	static const int WIDTH = 4;  // һ����λ���
	vector<int> v;
	int tag = 0 ;                // ����λ 0 +  1 -
	//���캯�� ��ֵ�����������
	BigInteger( long long num = 0 ) { *this = num; }
	BigInteger( const string &str ) { *this = str; }
	//���ظ�ֵ����� long long �汾
	BigInteger operator = (long long num)
	{
		v.clear();
		num < 0 ? tag = 1 : tag = 0;
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
		str[0]=='-' ? tag = 1 : tag =0;
		/* len ����������ʹ�䱣֤����
		 * strlen  len  (��kΪ����)
		 *  k*B-1   k
		 *  k*B     k
		 *  k*B+1   k               */
		int tmp, len = (str.length() - 1) / WIDTH + 1, head = (tag ? 1 : 0);
		for(int i(0); i < len; ++i)
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
			return tag > b.tag;            // 1 > 0
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
	BigInteger operator + (const BigInteger &b)const
	{
		BigInteger res;
		res.v.clear();
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

	BigInteger operator - (const BigInteger &b)const
	{
		BigInteger res = *this;
		return res;
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
	return 0;
}
struct big {
    typedef ll INT;
    static const INT S=100000000;
    static const int S_n=9;
    static const int SIZE=305;
    INT a[SIZE]; int len, tag;
    big() { len=1; CC(a, 0); }
    big(char *s) { len=1; CC(a, 0); *this=s; }
    big(INT x) { len=1; CC(a, 0); *this=x; }
    void cln() { memset(a, 0, sizeof(INT)*(len+1)); len=1; tag=0; }
    void fix() { while(len>1 && !a[len]) --len; }
    void M(big &a, big &b, big &c) {
        if(b.tag) { b.tag=0; P(a, b, c); b.tag=1; return; }
        if(a.tag) { a.tag=0; P(a, b, c); a.tag=1; c.tag=1; return; }
        c.cln();
        int flag=0, i=1;
        big *x=&a, *y=&b;
        if(a<b) flag=1, swap(x, y);
        for(; i<=x->len; ++i) {
            c.a[i]+=x->a[i]-y->a[i];
            if(c.a[i]<0) c.a[i]+=S, --c.a[i+1];
        }
        c.len=i;
        c.fix();
        c.tag=flag;
    }
    void P(big &a, big &b, big &c) {
        if(b.tag) { b.tag=0; M(a, b, c); b.tag=1; return; }
        if(a.tag) { a.tag=0; M(b, a, c); a.tag=1; return; }
        c.cln();
        int i=1, l=max(a.len, b.len); INT k=0;
        for(; i<=l || k; ++i) {
            c.a[i]=a.a[i]+b.a[i]+k;
            k=c.a[i]/S;
            if(c.a[i]>=S) c.a[i]%=S;
        }
        c.len=i;
        c.fix();
    }
    void T(big &a, big &b, big &c) {
        c.cln();
        for1(i, 1, a.len) for1(j, 1, b.len) {
            int pos=i+j-1;
            c.a[pos]+=a.a[i]*b.a[j];
            c.a[pos+1]+=c.a[pos]/S;
            c.a[pos]%=S;
        }
        c.len=a.len+b.len;
        c.fix();
        c.tag=a.tag^b.tag;
        if(c.a[1]==0 && c.len==1) c.tag=0;
    }
    void D(big &a, INT b, big &c) {
        c.cln(); INT t=0;
        for(int i=len; i; --i) {
            c.a[i]=(a.a[i]+t)/b;
            t=((a.a[i]+t)%b)*S;
        }
        c.len=len;
        c.fix();
    }
    void D(big &a, big &b, big &c) {
        c.cln();
        big l, r=a, mid, TP, ONE=(INT)1;
        while(l<=r) {
            P(l, r, TP); D(TP, 2, mid);
            T(mid, b, TP);
            if(TP<=a) P(mid, ONE, l);
            else M(mid, ONE, r);
        }
        M(l, ONE, c);
        c.tag=a.tag^b.tag;
        if(c.a[1]==0 && c.len==1) c.tag=0;
    }
    big sqrt() {
        big l, r=*this, mid, TP, ONE=(INT)1;
        while(l<=r) {
            P(l, r, TP); D(TP, 2, mid);
            T(mid, mid, TP);
            if(TP<=*this) P(mid, ONE, l);
            else M(mid, ONE, r);
        }
        M(l, ONE, TP);
        return TP;
    }
    bool operator<(big &b) {
        if(b.tag && !tag) return 0;
        if(!b.tag && tag) return 1;
        if(b.tag && tag) { tag=b.tag=0; bool ret=b<*this; tag=b.tag=1; return ret; }
        if(len!=b.len) return len<b.len;
        for3(i, len, 1) if(a[i]<b.a[i]) return true; else if(a[i]>b.a[i]) return false; //����һ��Ҫע��
        return false;
    }
    big& operator= (INT b) {
        cln();
        len=0;
        if(b==0) { len=1; return *this; }
        if(b<0) tag=1, b=-b;
        while(b) { a[++len]=b%S; b/=S; }
        return *this;
    }
    big& operator= (char *s) {
        cln();
        if(s[0]=='-') tag=1, ++s;
        len=0; int l=strlen(s), t=0, k=1;
        for3(i, l-1, 0) {
            t=t+(s[i]-'0')*k;
            k*=10;
            if(k>=S) a[++len]=t%S, t=0, k=1;
        }
        if(k!=1) a[++len]=t%S;
        return *this;
    }
    big& operator= (const big &x) {
        cln();
        memcpy(a, x.a, sizeof(INT)*(x.len+1));
        len=x.len, tag=x.tag;
        return *this;
    }
    big operator+ (big x) { big c; P(*this, x, c); return c; }
    big operator- (big x) { big c; M(*this, x, c); return c; }
    big operator* (big x) { big c; T(*this, x, c); return c; }
    big operator/ (big x) { big c; D(*this, x, c); return c; }
    big operator/ (INT x) { big c; D(*this, x, c); return c; }
    big& operator+= (big x) { big c; P(*this, x, c); return *this=c; }
    big& operator-= (big x) { big c; M(*this, x, c); return *this=c; }
    big& operator*= (big x) { big c; T(*this, x, c); return *this=c; }
    big& operator/= (big x) { big c; D(*this, x, c); return *this=c; }
    big& operator/= (INT x) { big c; D(*this, x, c); return *this=c; }
    big& operator++ () { return *this+=1; }
    big operator++ (int) { big ret=*this; ++*this; return ret; }
    big& operator-- () { return *this-=1; }
    big operator-- (int) { big ret=*this; --*this; return ret; }
    bool operator> (big &x) { return x<*this; }
    bool operator== (big &x) { return x<=*this&&x>=*this; }
    bool operator<= (big &x) { return !(x<*this); }
    bool operator>= (big &x) { return !(x>*this); }
    void P() {
        if(tag) putchar('-');
        printf("%d", (int)a[len]);
        char od[8]; od[0]='%'; od[1]='0';
        sprintf(od+2, "%d", S_n-1);
        int l=strlen(od); od[l]='d'; od[l+1]='\0';
        for3(i, len-1, 1) printf(od, (int)a[i]);
    }
};
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
  
using namespace std;  
  
  
const int power = 1;      //ÿ�������λ��Ϊ10��power�η��������ﶨ��Ϊ�˷������ʵ��  
const int base = 10;      //10��power�η���  
  
  
//Ҫѹλ��ʱ��ֻ���power �� base���ɣ���ѹ��λ�߾�����ôpower = 4, base = 10000  
  
  
const int MAXL = 1001;    //����ĳ��ȡ�  
  
  
char a[MAXL], b[MAXL];  
struct num  
{  
    int a[MAXL];  
    num() { memset(a, 0, sizeof(a)); }                      //��ʼ��  
    num(char *s)                                            //��һ���ַ�����ʼ��Ϊ�߾�����  
    {  
        memset(a, 0, sizeof(a));  
        int len = strlen(s);  
        a[0] = (len+power-1) / power;                       //���ĳ���  
        for (int i=0, t=0, w; i < len ;w *= 10, ++i)          
        {  
            if (i % power == 0) { w = 1, ++t; }  
            a[t] += w * (s[i]-'0');  
        }  
        //��ʼ�����飬�����Լ�ģ��һ�£�Ӧ�ú����׶���~  
    }  
    void add(int k) { if (k || a[0]) a[ ++a[0] ] = k; }     //��ĩβ���һ������������ʱ��Ҫ�õ�  
    void re() { reverse(a+1, a+a[0]+1); }                   //������������������ʱ��Ҫ�õ�  
    void print()                                            //��ӡ�˸߾�����  
    {  
        printf("%d", a[ a[0] ]);        
        //�ȴ�ӡ���λ��Ϊ��ѹλ ���� �ø߾�����Ϊ0 ����  
        for (int i = a[0]-1;i > 0;--i)  
        printf("%0*d", power, a[i]);    
        //����"%0*d", power����˼�ǣ��������powerλ��������ǰ����0����  
        printf("\n");  
    }  
} p,q,ans;  
  
  
bool operator < (const num &p, const num &q)              //�ж�С�ڹ�ϵ��������ʱ������  
{  
    if (p.a[0] < q.a[0]) return true;  
    if (p.a[0] > q.a[0]) return false;  
    for (int i = p.a[0];i > 0;--i)  
    {  
        if (p.a[i] != q.a[i]) return p.a[i] < q.a[i];  
    }  
    return false;  
}  
  
  
num operator + (const num &p, const num &q)               //�ӷ������ö�˵�˰ɣ�ģ��һ�飬�����׶�  
{  
    num c;  
    c.a[0] = max(p.a[0], q.a[0]);  
    for (int i = 1;i <= c.a[0];++i)  
    {  
        c.a[i] += p.a[i] + q.a[i];  
        c.a[i+1] += c.a[i] / base;  
        c.a[i] %= base;  
    }  
    if (c.a[ c.a[0]+1 ]) ++c.a[0];  
    return c;  
}  
  
  
num operator - (const num &p, const num &q)               //������Ҳ���ö�˵��ģ��һ�飬�����׶�  
{  
    num c = p;  
    for (int i = 1;i <= c.a[0];++i)  
    {  
        c.a[i] -= q.a[i];  
        if (c.a[i] < 0) { c.a[i] += base; --c.a[i+1]; }  
    }  
    while (c.a[0] > 0 && !c.a[ c.a[0] ]) --c.a[0];            
    //�ҵ�ϰ�����������Ϊ0����ô���ĳ���Ҳ��0������Ƚϴ�С����ĩβ�����ʱ���жϡ�  
    return c;  
}  
  
  
num operator * (const num &p, const num &q)                   
//�˷�������ģ��һ�顣����ʵ�߾��Ⱦ���ģ���˹��������㣡  
{  
    num c;  
    c.a[0] = p.a[0]+q.a[0]-1;  
    for (int i = 1;i <= p.a[0];++i)  
    for (int j = 1;j <= q.a[0];++j)  
    {  
        c.a[i+j-1] += p.a[i]*q.a[j];  
        c.a[i+j] += c.a[i+j-1] / base;  
        c.a[i+j-1] %= base;  
    }  
    if (c.a[ c.a[0]+1 ]) ++c.a[0];  
    return c;  
}  
  
  
num operator / (const num &p, const num &q)               //��������������΢����һ��  
{  
    num x, y;  
    for (int i = p.a[0];i >= 1;--i)                       //�����λ��ʼȡ��  
    {  
        y.add(p.a[i]);             //������ĩβ�����λ������ʱ���Ǹ�λ��ǰ����λ�ں�  
        y.re();                    //��������������Ϊͳһ�Ĵ洢��ʽ����λ��ǰ����λ�ں�  
        while ( !(y < q) )         //���ڵ��ڳ�����ʱ�����С�ڵĻ�����ʵ���ϵĸ�λ���ǳ�ʼ�ġ�0��  
            y = y - q, ++x.a[i];   //���ܼ����������������Σ����ϸ�λ�ͼӼ��Ρ�  
        y.re();                    //������������Ϊ��һ��������׼��  
    }  
    x.a[0] = p.a[0];  
    while (x.a[0] > 0 && !x.a[x.a[0]]) --x.a[0];  
    return x;  
}  
