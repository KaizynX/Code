#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

long long n, p;
int a, b;

struct BigInteger
{
    static const int SIZE = 1e4; // 位数SIZE*4
    static const int BASE = 1e4; // 压位
    static const int WIDTH = 4;

    int v[SIZE], len;
    int tag; // 假装有正负符号

    BigInteger(long long num = 0) { *this = num; }
    BigInteger(const string &str) { *this = str; }
    // long long 转 BigInteger
    BigInteger operator = (long long num)
    {
        len = tag = 0;
        memset(v, 0, sizeof v);
        do
        {
            v[++len] = (int)(num%BASE);
            num /= BASE;
        } while(num > 0);
        return *this;
    }
    // string 转 BigInteger
    BigInteger operator = (const string &str)
    {
        string buf;
        int r = (int)str.length()-1, l = max(0, r-WIDTH+1);
        len = tag = 0;
        memset(v, 0, sizeof v);
        while(r >= 0)
        {
            buf = str.substr(l, r-l+1);
            sscanf(buf.c_str(), "%d", &v[++len]);
            r -= WIDTH; l = max(0, r-WIDTH+1);
        }
        return *this;
    }
    // 比较运算
    bool operator < (const BigInteger &b) const
    {
        if(len != b.len) return len < b.len;
        for(int i = len; i; --i)
            if(v[i] != b.v[i]) return v[i] < b.v[i];
        return false;
    }

    bool operator > (const BigInteger &b) const { return b < *this; }
    bool operator <= (const BigInteger &b) const { return !(b < *this); }
    bool operator >= (const BigInteger &b) const { return !(*this < b); }
    bool operator != (const BigInteger &b) const { return *this < b || b < *this; }
    bool operator == (const BigInteger &b) const { return !(*this < b) && !(b < *this); }
    // 四则运算
    BigInteger operator + (const BigInteger &b) const
    {
        BigInteger res = b;
        res.len = max(len, b.len);
        for(int i = 1; i <= len; ++i)
            res.v[i] += v[i];
        for(int i = 1; i <= res.len; ++i)
            res.v[i+1] += res.v[i]/BASE,
            res.v[i] %= BASE;
        while(res.v[res.len+1] > 0) res.len++;
        return res;
    }
    // 单目运算
    BigInteger operator + () const { return *this; }
    BigInteger operator - () const
    {
        BigInteger res = *this;
        res.tag ^= 1;
        return res;
    }

    BigInteger operator - (const BigInteger &b) const
    {
        if(*this < b) return -(b-*this);
        BigInteger res = *this;
        for(int i = 1; i <= b.len; ++i)
            res.v[i] -= b.v[i];
        for(int i = 1; i <= res.len; ++i)
            if(res.v[i] < 0)
                res.v[i] += BASE,
                res.v[i+1]--;
        while(res.len > 1 && res.v[res.len] == 0) res.len--;
        return res;
    }
    // 高精度乘低精度
    BigInteger operator * (int b) const
    {
        BigInteger res;
        long long tmp;
        res.len = len;
        for(int i = 1; i <= len; ++i)
        {
            tmp = 1ll*b*v[i];
            res.v[i] += (int)(tmp%BASE);
            res.v[i+1] += (int)(tmp/BASE+res.v[i]/BASE);
            res.v[i] %= BASE;
        }
        while(res.v[res.len+1] > 0) res.len++;
        return res;
    }
    // 高精度乘高精度
    BigInteger operator * (const BigInteger &b) const
    {
        BigInteger res;
        res.len = len+b.len;
        for(int i = 1; i <= len; ++i)
            for(int j = 1; j <= b.len; ++j)
            {
                res.v[i+j-1] += v[i]*b.v[j];
                res.v[i+j] += res.v[i+j-1]/BASE;
                res.v[i+j-1] %= BASE;
            }
        while(res.len > 1 && res.v[res.len] == 0) res.len--;
        return res;
    }
    // 高精度除低精度
    BigInteger operator / (int b) const
    {
        long long divisor = 0;
        BigInteger res;
        for(int i = len; i; --i)
        {
            divisor = divisor*BASE+v[i];
            if(divisor < b) continue;
            res.v[i] = (int)(divisor/b);
            divisor %= b;
            res.len = max(res.len, i);
        }
        return res;
    }
    // 高精度除高精度
    BigInteger operator / (const BigInteger &b) const
    {
        BigInteger divisor, res;
        int l, r, mid;
        for(int i = len; i; --i)
        {
            divisor = divisor*BASE+v[i];
            /*
            memcpy(divisor.v+1, divisor.v, sizeof(int)*(divisor.len+1));
            while(divisor.v[divisor.len+1] > 0) divisor.len++;
            divisor.v[1] = v[i];
            */
            if(divisor < b) continue;
            l = 0; r = BASE-1;
            while(l < r)
            {
                mid = (l+r+1)>>1;
                if(b*mid <= divisor) l = mid;
                else r = mid-1;
            }
            divisor -= b*l;
            res.v[i] = l;
            res.len = max(res.len, i);
        }
        return res;
    }

    BigInteger operator % (const BigInteger &b) const { return *this-*this/b*b; }

    BigInteger operator ++ () { return *this = *this+1; }
    BigInteger operator -- () { return *this = *this-1; }
    BigInteger operator += (const BigInteger &b) { return *this = *this+b; }
    BigInteger operator -= (const BigInteger &b) { return *this = *this-b; }
    BigInteger operator *= (const BigInteger &b) { return *this = *this*b; }
    BigInteger operator /= (const BigInteger &b) { return *this = *this/b; }
    BigInteger operator %= (const BigInteger &b) { return *this = *this%b; }
    BigInteger operator *= (int b) { return *this = *this*b; }
    BigInteger operator /= (int b) { return *this = *this/b; }
    BigInteger operator %= (int b) { return *this = *this%b; }
};

// 重载输入运算符
istream &operator >> (istream &in, BigInteger &big)
{
    string buf;
    if(in >> buf) big = buf;
    return in;
}
// 重载输出运算符
ostream &operator << (ostream &os, const BigInteger &big)
{
    char buf[10];
    if(big.tag) os << '-';
    os << big.v[big.len];
    for(int i = big.len-1; i; --i)
    {
        sprintf(buf, "%04d", big.v[i]);
        for(int j = 0; j < 4; ++j) os << buf[j];
    }
    return os;
}

int exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return a; }
    int res = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return res;
}

int main()
{
    cin >> n >> p >> a >> b;
    int x, y;
    int g = exgcd(a, b, x, y), ag = a/g, bg = b/g;
    // ax+by = gcd(a, b);
    if (p%g) { cout << -1 << endl; return 0; }
    BigInteger xx = p/g, yy = p/g, cg;
    xx *= x; yy *= y;
    // turn xx,yy to be +
    if (xx < 0) {
        cg = -xx/bg+(xx%bg != 0);
        xx += cg*bg;
        yy -= cg*ag;
    }
    if (yy < 0) {
        cg = -yy/ag+(yy%ag != 0);
        xx -= cg*bg;
        yy += cg*ag;
    }
    if (xx < 0 || yy < 0) { cout << -1 << endl; return 0; }
    cg = yy/ag;
    xx += cg*bg;
    yy -= cg*ag;
    if (xx+yy > n) { cout << -1 << endl; return 0; }
    cout << xx << " " << yy << " " << -xx-yy+n << endl;
    return 0;
}
