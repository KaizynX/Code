/*
 * @Author: Kaizyn
 * @Date: 2021-10-03 13:38:22
 * @LastEditTime: 2021-10-03 13:43:09
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
#define log(x) (31-__builtin_clz(x))
const int N = 2e6+7;

namespace SuffixArray {

int sa[N], rk[N], ht[N];
bool t[N << 1];

inline bool islms(const int i, const bool *t) { return i > 0 && t[i] && !t[i - 1]; }

template <class T>
inline void sort(T s, int *sa, const int len, const int sz, const int sigma, bool *t, int *b, int *cb, int *p) {
  memset(b, 0, sizeof(int) * sigma);
  memset(sa, -1, sizeof(int) * len);
  for (int i = 0; i < len; i++) b[static_cast<int>(s[i])]++;
  cb[0] = b[0];
  for (int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i];
  for (int i = sz - 1; i >= 0; i--) sa[--cb[static_cast<int>(s[p[i]])]] = p[i];
  for (int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i - 1];
  for (int i = 0; i < len; i++)
    if (sa[i] > 0 && !t[sa[i] - 1])
      sa[cb[static_cast<int>(s[sa[i] - 1])]++] = sa[i] - 1;
  cb[0] = b[0];
  for (int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i];
  for (int i = len - 1; i >= 0; i--)
    if (sa[i] > 0 && t[sa[i] - 1])
      sa[--cb[static_cast<int>(s[sa[i] - 1])]] = sa[i] - 1;
}

template <class T>
inline void sais(T s, int *sa, const int len, bool *t, int *b, int *b1, const int sigma) {
  int i, j, x, p = -1, cnt = 0, sz = 0, *cb = b + sigma;
  for (t[len - 1] = 1, i = len - 2; i >= 0; i--) t[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && t[i + 1]);
  for (i = 1; i < len; i++)
    if (t[i] && !t[i - 1])
      b1[sz++] = i;
  sort(s, sa, len, sz, sigma, t, b, cb, b1);
  for (i = sz = 0; i < len; i++)
    if (islms(sa[i], t))
      sa[sz++] = sa[i];
  for (i = sz; i < len; i++) sa[i] = -1;
  for (i = 0; i < sz; i++) {
    for (x = sa[i], j = 0; j < len; j++) {
      if (p == -1 || s[x + j] != s[p + j] || t[x + j] != t[p + j]) {
        cnt++, p = x;
        break;
      } else if (j > 0 && (islms(x + j, t) || islms(p + j, t))) {
        break;
      }
    }
    sa[sz + (x >>= 1)] = cnt - 1;
  }
  for (i = j = len - 1; i >= sz; i--)
    if (sa[i] >= 0)
      sa[j--] = sa[i];
  int *s1 = sa + len - sz, *b2 = b1 + sz;
  if (cnt < sz)
    sais(s1, sa, sz, t + len, b, b1 + sz, cnt);
  else
    for (i = 0; i < sz; i++) sa[s1[i]] = i;
  for (i = 0; i < sz; i++) b2[i] = b1[sa[i]];
  sort(s, sa, len, sz, sigma, t, b, cb, b2);
}

template <class T>
inline void getHeight(T s, int n) {
  for (int i = 1; i <= n; i++) rk[sa[i]] = i;
  int j = 0, k = 0;
  for (int i = 0; i < n; ht[rk[i++]] = k)
    for (k ? k-- : 0, j = sa[rk[i] - 1]; s[i + k] == s[j + k]; k++)
      ;
}

template <class T>  // s start from 0
inline void init(T s, const int len, const int sigma = 128) {
  sais(s, sa, len + 1, t, rk, ht, sigma);
  getHeight(s, len);
  for (int i = 1; i <= len; ++i) ++sa[i];
  for (int i = len; i; --i) rk[i] = rk[i-1];
}
}; 

int n;
char s[N];
int *sa = SuffixArray::sa, *ht = SuffixArray::ht;
int t[N], rk[N];
void tsort(vector<vector<int>> &v) {
  for (auto i : v) ++t[i[0]];
  for (int i = 1; i <= n; ++i) t[i] += t[i-1];
  for (int i = 0; i < (int)v.size(); ++i) rk[--t[v[i][0]]] = i;
}

inline void solve() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = n; i < 2*n; ++i) s[i] = s[i-n];
  SuffixArray::init(s, 2*n);
  #ifdef DEBUG
  orzarr(sa+1, 2*n);
  orzarr(ht+1, 2*n);
  #endif
  vector<int> v;
  vector<vector<int>> ans;
  for (int i = 1, j; i <= 2*n; i = j) {
    v.clear();
    if (sa[i] <= n) v.emplace_back(sa[i]);
    for (j = i+1; j <= 2*n; ++j) {
      if (ht[j] < n) break;
      if (sa[j] <= n) v.emplace_back(sa[j]);
    }
    if (v.empty()) continue;
    sort(v.begin(), v.end());
    ans.emplace_back(v);
  }
  tsort(ans);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    vector<int> &v = ans[rk[i]];
    printf("%d", (int)v.size());
    for (int i : v) printf(" %d", i-1);
    puts("");
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}