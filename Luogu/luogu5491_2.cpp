/*
 * @Author: Kaizyn
 * @Date: 2021-02-19 16:54:57
 * @LastEditTime: 2021-02-19 17:00:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

namespace ecsy { // 二次剩余

inline int lrd(int x, int mod) { return qpow(x,mod>>1, mod); }//勒让德符号

struct cplx
{
  int x,y;
  inline friend cplx operator *(cplx a,cplx b)
  {
    return {(1ll*a.x*b.x+1ll*a.y*b.y%MOD*w)%MOD,(1ll*a.x*b.y+1ll*a.y*b.x)%MOD};
  }
  inline friend cplx operator ^(cplx a,int b)
  {
    cplx c={1,0};
    while(b){if(b&1)c=c*a; a=a*a; b>>=1;}
    return c;
  }
}a;

void solve() {
  scanf("%d%d",&n,&MOD); n%=MOD;
  x=lrd(n);
  if(x==MOD-1)printf("Hola!\n");
  else if(!x)printf("0\n");
  else
  {
    x=rand()%(MOD-1)+1; w=(1ll*x*x-n+MOD)%MOD;
    while(lrd(w)<=1)x=rand()%MOD,w=(1ll*x*x-n+MOD)%MOD;
    a={x,1}; a=a^(MOD+1>>1);
    ans1=a.x; ans2=MOD-a.x; if(ans1>ans2)swap(ans1,ans2);
    printf("%d %d\n",ans1,ans2);
  }
}
}

inline void solve() {
  ;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}