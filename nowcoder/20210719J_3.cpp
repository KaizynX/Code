/*
 * @Author: Kaizyn
 * @Date: 2021-07-19 13:06:16
 * @LastEditTime: 2021-07-19 15:52:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
// #define int ll
const int INF = 0x3f3f3f3f;
const ll Z = 11'000'000'000'027ll;
// const ll INF = 1e18;
const int N = 4e4+7;
const int M = 8e4+7;
const int K = 31;

int n, m, k;
ll P, phi;
vector<ll> v;
int a[N], t[M];
ll f[M], f2[M], C[N][K], C2[N][K];
inline ll mul(ll a,ll b,ll mod){
	return (__int128)a*b%mod;
}
inline ll pow(ll a,ll b,ll mod){
	ll res=1;
	if(a>=mod)a%=mod;
	while(b){
		if(b&1)res=mul(res,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return res;
}
bool miller_rabin(ll a,ll n){
	ll d=n-1,r=0;
	while(!(d&1))d>>=1,r++;
	ll x=pow(a,d,n);
	if(x==1)return 1;
	for(int i=0;i<r;i++){
		if(x==n-1)return 1;
		x=mul(x,x,n);
	}
	return 0;
}
bool is_prime(ll x){
	if(x<=1)return 0;
	static int num[]={2,3,5,7,13,29,37,89};
	for(int i=0;i<8;i++)if(x==num[i])return 1;
	for(int i=0;i<8;i++)if(!miller_rabin(num[i],x))return 0;
	return 1;
}
ll fun(ll x,ll c,ll mod){
	return (mul(x,x,mod)+c)%mod;
}
ll gcd(ll n,ll m){
	if(m==0)return n;
	return gcd(m,n%m);
}
ll pollard_rho(ll x){
	ll c=rand()%(x-1)+1;
	ll s=0,t=0;
	for(int goal=1;;goal<<=1,s=t){
		ll val=1;
		for(int step=1;step<=goal;step++){
			t=fun(t,c,x);
			val=mul(val,abs(s-t),x);
			if(step%127==0){
				ll d=gcd(val,x);
				if(d>1)return d;
			}
		}
		ll d=gcd(val,x);
		if(d>1)return d;
	}
}
void find_fac(ll x){
	if(x==1)return;
	if(is_prime(x)){
    v.emplace_back(x);
		return;
	}
	ll y=x;
	while(y==x)y=pollard_rho(x);
	find_fac(y),find_fac(x/y);
}


void init() {
  for (int i = 0; i <= n; ++i) {
    C[i][0] = C2[i][0] = 1;
    if (i <= k) C[i][i] = C2[i][i] = 1;
    for (int j = 1; j <= min(i/2, k); ++j) {
      C[i][j] = (C[i-1][j]+C[i-1][j-1])%phi;
      C2[i][j] = (C2[i-1][j]+C2[i-1][j-1])%Z;
      if (i-j <= k) C[i][i-j] = C[i][j], C2[i][i-j] = C2[i][j];
    }
  }
}

void getphi() {
  v.clear();
  find_fac(P);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  phi = P;
  for (int i : v) {
    phi = phi/i*(i-1);
  }
}

inline void solve() {
  cin >> n >> k >> P;
  getphi();
  m = 0;
  init();
  ll res = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++t[a[i]];
    m = max(m, a[i]);
  }
  for (int g = m; g; --g) {
    int cnt = 0;
    for (int i = g; i <= m; i += g) {
      f[g] -= f[i]; 
      f2[g] -= f2[i];
      cnt += t[i];
    }
    f[g] = ((f[g]+C[cnt][k])%phi+phi)%phi;
    f2[g] = ((f2[g]+C2[cnt][k])%Z+Z)%Z;
    res = mul(res, pow(g, f[g]+(f[g] != f2[g])*phi, P), P);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    solve();
    for (int i = 1; i <= n; ++i) --t[a[i]];
    for (int i = 1; i <= m; ++i) f[i] = f2[i] = 0;
  }
  return 0;
}