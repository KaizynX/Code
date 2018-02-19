#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
//高精度压位
struct BigInteger
{
	static const int BASE = 1e5; // % 下来一个单位就是 0 ~ 9999
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
		num < 0 ? tag = 1 : tag = 0;
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
		str[0]=='-' ? tag = 1 : tag =0;
		/* len 的神奇运算使其保证合理
		 * strlen  len  (设k为常数)
		 *  k*B-1   k
		 *  k*B     k
		 *  k*B+1   k               */
		int tmp, len = (str.length() - 1) / WIDTH + 1, head = (tag ? 1 : 0);
		for(int i(0); i < len; ++i)
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
			return tag > b.tag;            // 1 > 0
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
		BigInteger res;
		res.v.clear();
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

	BigInteger operator - (const BigInteger &b)const
	{
		BigInteger res = *this;
		return res;
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
        for3(i, len, 1) if(a[i]<b.a[i]) return true; else if(a[i]>b.a[i]) return false; //这里一定要注意
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
  
  
const int power = 1;      //每次运算的位数为10的power次方，在这里定义为了方便程序实现  
const int base = 10;      //10的power次方。  
  
  
//要压位的时候，只需改power 和 base即可，如压万位高精，那么power = 4, base = 10000  
  
  
const int MAXL = 1001;    //数组的长度。  
  
  
char a[MAXL], b[MAXL];  
struct num  
{  
    int a[MAXL];  
    num() { memset(a, 0, sizeof(a)); }                      //初始化  
    num(char *s)                                            //将一个字符串初始化为高精度数  
    {  
        memset(a, 0, sizeof(a));  
        int len = strlen(s);  
        a[0] = (len+power-1) / power;                       //数的长度  
        for (int i=0, t=0, w; i < len ;w *= 10, ++i)          
        {  
            if (i % power == 0) { w = 1, ++t; }  
            a[t] += w * (s[i]-'0');  
        }  
        //初始化数组，这里自己模拟一下，应该很容易懂的~  
    }  
    void add(int k) { if (k || a[0]) a[ ++a[0] ] = k; }     //在末尾添加一个数，除法的时候要用到  
    void re() { reverse(a+1, a+a[0]+1); }                   //把数反过来，除法的时候要用到  
    void print()                                            //打印此高精度数  
    {  
        printf("%d", a[ a[0] ]);        
        //先打印最高位，为了压位 或者 该高精度数为0 考虑  
        for (int i = a[0]-1;i > 0;--i)  
        printf("%0*d", power, a[i]);    
        //这里"%0*d", power的意思是，必须输出power位，不够则前面用0补足  
        printf("\n");  
    }  
} p,q,ans;  
  
  
bool operator < (const num &p, const num &q)              //判断小于关系，除法的时候有用  
{  
    if (p.a[0] < q.a[0]) return true;  
    if (p.a[0] > q.a[0]) return false;  
    for (int i = p.a[0];i > 0;--i)  
    {  
        if (p.a[i] != q.a[i]) return p.a[i] < q.a[i];  
    }  
    return false;  
}  
  
  
num operator + (const num &p, const num &q)               //加法，不用多说了吧，模拟一遍，很容易懂  
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
  
  
num operator - (const num &p, const num &q)               //减法，也不用多说，模拟一遍，很容易懂  
{  
    num c = p;  
    for (int i = 1;i <= c.a[0];++i)  
    {  
        c.a[i] -= q.a[i];  
        if (c.a[i] < 0) { c.a[i] += base; --c.a[i+1]; }  
    }  
    while (c.a[0] > 0 && !c.a[ c.a[0] ]) --c.a[0];            
    //我的习惯是如果该数为0，那么他的长度也是0，方便比较大小和在末尾添加数时的判断。  
    return c;  
}  
  
  
num operator * (const num &p, const num &q)                   
//乘法，还是模拟一遍。。其实高精度就是模拟人工四则运算！  
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
  
  
num operator / (const num &p, const num &q)               //除法，这里我稍微讲解一下  
{  
    num x, y;  
    for (int i = p.a[0];i >= 1;--i)                       //从最高位开始取数  
    {  
        y.add(p.a[i]);             //把数添到末尾（最低位），这时候是高位在前，低位在后  
        y.re();                    //把数反过来，变为统一的存储方式：低位在前，高位在后  
        while ( !(y < q) )         //大于等于除数的时候，如果小于的话，其实答案上的该位就是初始的“0”  
            y = y - q, ++x.a[i];   //看能减几个除数，减几次，答案上该位就加几次。  
        y.re();                    //将数反过来，为下一次添数做准备  
    }  
    x.a[0] = p.a[0];  
    while (x.a[0] > 0 && !x.a[x.a[0]]) --x.a[0];  
    return x;  
}  
