/*
 * @Author: Kaizyn
 * @Date: 2021-10-13 13:15:51
 * @LastEditTime: 2021-10-13 13:25:47
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
const int N = 2e5+7;

struct Node {
  int l, r, id;
};

int n, q, block;
int a[N], res[N], cnt[N];
Node b[N];

bool cmp(const Node &q1, const Node &q2) {
  return q1.l/block != q2.l/block ? q1.l < q2.l :
      (q1.l/block)&1 ? q1.r < q2.r : q1.r > q2.r;
}

inline void solve() {
  block = n/(sqrt(q)+.5)+1;
  for (int i = 1; i <= n; ++i) {
    cnt[i] = 0;
    cin >> a[i];
    a[n+i] = a[i];
  }
  for (int i = 1; i <= q; ++i) {
    b[i].id = i;
    cin >> b[i].r >> b[i].l;
    if (b[i].r >= b[i].l) {
      b[i].l = 1;
      b[i].r = n;
    } else {
      b[i].r += n;
    }
  }
  sort(b+1, b+q+1, cmp);
  // 移动前两步先扩大区间 $l--,r++$ 后两步缩小区间 $l++,r--$
  for (int i = 1, l = 1, r = 0, num = 0; i <= q; ++i) {
    while (l > b[i].l) if (++cnt[a[--l]] == 1) ++num;
    while (r < b[i].r) if (++cnt[a[++r]] == 1) ++num;
    while (l < b[i].l) if (--cnt[a[l++]] == 0) --num;
    while (r > b[i].r) if (--cnt[a[r--]] == 0) --num;
    res[b[i].id] = num;
  }
  for (int i = 1; i <= q; ++i) {
    cout << res[i] << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  while (cin >> n >> q) solve();
  return 0;
}