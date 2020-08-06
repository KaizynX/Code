/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 21:13:25
 * @LastEditTime: 2020-07-18 09:31:06
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int M[2] = {805306457, 1000173169};
const int P[2] = {27, 31};

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

int n;
char s[N];
int res[N];
int sa[N], rk[N<<1], height[N];
mint val[N], pw10[N];
long long str_hash[2][N], pM[2][N];

template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
  static int oldrk[N<<1];
  memset(rk+n+1, 0, sizeof(int)*n);
  for (int i = 1; i <= n; ++i) rk[i] = s[i];
  for (int w = 1; w <= n; w <<= 1) {
    iota(sa+1, sa+n+1, 1);
    sort(sa+1, sa+n+1, [&](const int &x, const int &y) {
      return rk[x] == rk[y] ? rk[x+w] < rk[y+w] : rk[x] < rk[y];
    });
    memcpy(oldrk+1, rk+1, sizeof(int)*2*n);
    for (int p = 0, i = 1; i <= n; ++i) {
      if (oldrk[sa[i]] == oldrk[sa[i-1]] &&
        oldrk[sa[i]+w] == oldrk[sa[i-1]+w]) {
        rk[sa[i]] = p;
      } else {
        rk[sa[i]] = ++p;
      }
    }
  }
  for (int i = 1, k = 0; i <= n; ++i) {
    if (k) --k;
    while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
    height[rk[i]] = k;
  }
}

void get_hash() {
  pM[0][0] = pM[1][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      str_hash[j][i] = (str_hash[j][i-1]*P[j]+s[i]-'0'+1)%M[j];
      pM[j][i] = pM[j][i-1]*P[j]%M[j];
    }
  }
}

inline bool cmp(const int &st, const int &len) {
  long long hash_val[2];
  for (int j = 0; j < 2; ++j) {
    hash_val[j] = (str_hash[j][st+len-1]-str_hash[j][st-1]*pM[j][len]%M[j]+M[j])%M[j];
  }
  return hash_val[0] == str_hash[0][len] && hash_val[1] == str_hash[1][len];
}

inline void solve() {
  scanf("%s", s+1);
  n = strlen(s+1);
  SA(s, n);
  pw10[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw10[i] = pw10[i-1]*10;
    val[i] = val[i-1]*10+s[i]-'0';
  }
  get_hash();
  for (int i = 1; i <= n; ++i) res[i] = i;
  sort(res+1, res+n+1, [](int i, int j) {
    int flag = 0;
    if (i > j) swap(i, j), flag = 1;
    if (cmp(i+1, j-i)) return flag^(rk[1] < rk[j-i+1]);
    return flag^(rk[1] > rk[i+1]);
  });
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " \n"[i==n];
  }
  cout << cmp(5, 1) << endl;
  // for (int i = 1; i <= n; ++i) cout << str_hash[0][i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << pM[0][i] << " \n"[i==n];
  #endif
  mint ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans *= pw10[res[i]];
    ans += val[res[i]];
  }
  cout << ans << endl;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}