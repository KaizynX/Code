#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
const LL MAXN = 1e2 + 10;
 
 
template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}
 
template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}
 
struct Node
{
    int C, M;
    bool operator < (const Node &nex) const {
        return M < nex.M;
    }
} a[MAXN];

__int128 C[MAXN], M[MAXN], x, y;
LL K,m;
__int128 gcd(__int128 a, __int128 b) {
    return b == 0 ? a : gcd(b, a % b);
}
__int128 exgcd(__int128 a, __int128 b, __int128 &x, __int128 &y) {
    if (b == 0) {x = 1, y = 0; return a;}
    __int128 r = exgcd(b, a % b, x, y), tmp;
    tmp = x; x = y; y = tmp - (a / b) * y;
    return r;
}
__int128 inv(__int128 a, __int128 b) {
    __int128 r = exgcd(a, b, x, y);
    while (x < 0) x += b;
    return x;
}
int main() {
    cin>>K>>m;
        for (LL i = 1; i <= K; i++) read(a[i].M),read(a[i].C);
        sort(a+1, a+K+1);
        for (int i = 1; i <= K; ++i) M[i] = a[i].M, C[i] = a[i].C;
        bool flag = 1;
        bool flag2=1;
        for (LL i = 2; i <= K; i++) {
            __int128 M1 = M[i - 1], M2 = M[i], C2 = C[i], C1 = C[i - 1], T = gcd(M1, M2);
            if ((C2 - C1) % T != 0) {flag = 0; break;}
            M[i] = (M1 * M2) / T;
            C[i] = ( inv( M1 / T , M2 / T ) * (C2 - C1) / T ) % (M2 / T) * M1 + C1;
            C[i] = (C[i] % M[i] + M[i]) % M[i];
            if(C[i]>m){
                flag2=0;
                break;
            }
        }
        if(flag==0) cout<<"he was definitely lying"<<endl;
        else if(flag2==0)
                cout<<"he was probably lying"<<endl;
        else  {
            write(C[K]);
            cout<<endl;
        }
    return 0;
}
