/*
 * @Author: Kaizyn
 * @Date: 2020-06-28 13:10:26
 * @LastEditTime: 2020-06-28 13:15:06
 */ 
/*
对于A的任何一种排列
　　设B至少i个位置和A相同：C(n,i)*A(m-i,n-i)
对上面那个容斥下就行
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define N 500005
#define DEBUG
const int MOD = 1e9+7;

template <int _MOD> struct Mint {
  int v = 0;
  Mint() {}
  Mint(int _v) : v((_v%_MOD+_MOD)%_MOD) {}
  Mint(long long _v) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
  Mint operator = (const int &_v) { return *this = Mint(_v); }
  Mint operator = (const long long &_v) { return *this = Mint(_v); }
  bool operator ! () const { return !this->v; }
  bool operator < (const Mint &b) const { return v < b.v; }
  bool operator > (const Mint &b) const { return v > b.v; }
  bool operator == (const Mint &b) const { return v == b.v; }
  bool operator != (const Mint &b) const { return v != b.v; }
  bool operator <= (const Mint &b) const { return v < b.v || v == b.v; }
  bool operator >= (const Mint &b) const { return v > b.v || v == b.v; }
  Mint operator + (const Mint &b) const { return Mint(v+b.v); }
  Mint operator - (const Mint &b) const { return Mint(v-b.v); }
  Mint operator * (const Mint &b) const { return Mint(1ll*v*b.v); }
  Mint operator / (const Mint &b) const { return Mint(b.inv()*v); }
  Mint& operator += (const Mint &b) { return *this = *this+b; }
  Mint& operator -= (const Mint &b) { return *this = *this-b; }
  Mint& operator *= (const Mint &b) { return *this = *this*b; }
  Mint& operator /= (const Mint &b) { return *this = *this/b; }
  Mint operator - () const { return Mint(-v); }
  Mint& operator ++ () { return *this += 1; }
  Mint& operator -- () { return *this -= 1; }
  Mint operator ++ (int) { Mint tmp = *this; *this += 1; return tmp; }
  Mint operator -- (int) { Mint tmp = *this; *this -= 1; return tmp; }
  Mint pow(int p) const {
    Mint res(1), x(*this);
    while (p) {
      if (p&1) res = res*x;
      x *= x;
      p >>= 1;
    }
    return res;
  }
  Mint inv() const { return pow(_MOD-2); }
  friend istream& operator >> (istream &is, Mint &mt) { return is >> mt.v; }
  friend ostream& operator << (ostream &os, const Mint &mt) { return os << mt.v; }
};
using mint = Mint<MOD>;

struct Combination {
  int fac[N], inv[N];
  void init(const int &n) {
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fac[i] = 1ll*fac[i-1]*i%MOD;
      inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i <= n; ++i) {
      inv[i] = 1ll*inv[i]*inv[i-1]%MOD;
    }
  }
  int A(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[p-q]%MOD : 0;
  }
  int C(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[p-q]%MOD*inv[q]%MOD : 0;
  }
};

Combination comb;
ll n,m,ans;

ll F[N], Finv[N], inv[N];///F是阶层 Finv是逆元的阶层
void init(){
    inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = (mod - mod/i) * 1ll * inv[mod % i] % mod;
    F[0] = Finv[0] = 1;
    for(int i = 1; i < N; i++){
        F[i] = F[i-1] * 1ll * i % mod;
        Finv[i] = Finv[i-1] * 1ll * inv[i] % mod;
    }
}
int C(int n, int m){ 
    if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n-m] % mod * Finv[m] % mod;
}
int main(){
    cin>>n>>m;
    init();
    ans=C(m,n)*F[n]%mod;
  comb.init(m);
  mint res = comb.A(m, n);
    
  for (int i = 1; i <= n; ++i) {
    res += comb.C(n, i)*comb.A(m-i, n-i)*(i&1 ? -1 : 1);
        ll flag=(i%2)?-1:1;
        ll tmp = C(n,i);
        tmp = tmp*C(m-i,n-i)%mod;
        tmp = tmp*F[n-i]%mod;
        ans=(ans+flag*tmp+2*mod)%mod;
    if (res-ans != 0) cout << i << endl;
  }
  cout << res*comb.A(m, n) << endl;
    cout<<ans*C(m,n)%mod*F[n]%mod<<'\n';
}