#include <bits/stdc++.h>
using namespace std;
#define LL long long
const long long MAXN = 1e2 + 10;
struct BigInteger
{
    static const int SIZE = 100; // λ��SIZE*4
    static const int BASE = 1e4; // ѹλ
    static const int WIDTH = 4;

    int v[SIZE], len;
    int tag; // ��װ����������

    BigInteger(long long num = 0) { *this = num; }
    BigInteger(const string &str) { *this = str; }
    // long long ת BigInteger
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
    // string ת BigInteger
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
    // �Ƚ�����
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
    // ��������
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
    // ��Ŀ����
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
    // �߾��ȳ˵;���
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
    // �߾��ȳ˸߾���
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
    // �߾��ȳ��;���
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
    // �߾��ȳ��߾���
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

// �������������
istream &operator >> (istream &in, BigInteger &big)
{
    string buf;
    if(in >> buf) big = buf;
    return in;
}
// ������������
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
inline void print(BigInteger &bbb)
{
    cout << bbb.len << ":";
    for (int i = 1; i <= bbb.len+1; ++i)
        cout << bbb.v[i] << " ";
    cout << endl;
}
// ��
template <typename T>
BigInteger pow (BigInteger a, T p)
{
    if(p == 0) return 1;
    BigInteger res = 1;
    while(p)
    {
        if(p%2) res *= a;
        a *= a;
        p /= 2;
    }
    return res;
}
// ����
BigInteger sqrt(const BigInteger &a, const int p = 2)
{
    BigInteger l, r = a, mid;
    while(l < r)
    {
        mid = (l+r+1)/2;
        if(pow(mid, p) <= a) l = mid;
        else r = mid-1;
    }
    return l;
}

BigInteger C[MAXN], M[MAXN];
BigInteger x, y;
int K;
BigInteger gcd(BigInteger a, BigInteger b) {
    return b == 0 ? a : gcd(b, a % b);
}
BigInteger exgcd(BigInteger a, BigInteger b, BigInteger &x, BigInteger &y) {
    if (b == 0) {x = 1, y = 0; return a;}
    BigInteger r = exgcd(b, a % b, x, y), tmp;
    tmp = x; x = y; y = tmp - (a / b) * y;
    return r;
}
BigInteger inv(BigInteger a, BigInteger b) {
    BigInteger r = exgcd(a, b, x, y);
    while (x < 0) x += b;
    return x;
}
int main() {
	LL m;
    cin>>K>>m;
        for (LL i = 1; i <= K; i++) cin>>M[i]>>C[i];
        bool flag = 1;
        for (LL i = 2; i <= K; i++) {
            BigInteger M1 = M[i - 1], M2 = M[i], C2 = C[i], C1 = C[i - 1], T = gcd(M1, M2);
            if ((C2 - C1) % T != 0) {flag = 0; break;}
            M[i] = (M1 * M2) / T;
            C[i] = ( inv( M1 / T , M2 / T ) * (C2 - C1) / T ) % (M2 / T) * M1 + C1;
            C[i] = (C[i] % M[i] + M[i]) % M[i];
        }
        if(flag==0) cout<<"he was definitely lying"<<endl;
        else if(C[K]>m)
        		cout<<"he was probably lying"<<endl;
		else  cout<<C[K]<<endl;
    return 0;
}
