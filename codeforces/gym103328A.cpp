/*
 * @Author: Kaizyn
 * @Date: 2021-11-03 16:54:25
 * @LastEditTime: 2021-11-03 17:06:18
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
const int N = 1e5+7;

struct Seg {
  struct Node {
    int tag, sum;
    Node *lc, *rc;
    Node() { tag = sum = 0; }
  } *root = nullptr;
  void init(Node *&rt) {
    if (!rt) return;
    init(rt->lc);
    init(rt->rc);
    delete rt;
    rt = nullptr;
  }
  void push_up(Node *&rt) {
    rt->sum = 0;
    if (rt->lc) rt->sum += rt->lc->sum;
    if (rt->rc) rt->sum += rt->rc->sum;
  }
  void push_down(Node *&rt) {
    if (!rt->tag) return;
    if (rt->lc) rt->lc->tag = 1, rt->lc->sum = 0;
    if (rt->rc) rt->rc->tag = 1, rt->rc->sum = 0;
    rt->tag = 0;
  }
  void add(int x, int k, Node *&rt, int l = -1e9, int r = 1e9) {
    if (!rt) rt = new Node();
    if (l == r) return rt->sum += k, void();
    push_down(rt);
    int mid = (l+r)/2;
    if (x <= mid) add(x, k, rt->lc, l, mid);
    else add(x, k, rt->rc, mid+1, r);
    push_up(rt);
  }
  void clear(int L, int R, Node *&rt, int l = -1e9, int r = 1e9) {
    if (!rt) return;
    if (l <= L && R >= r) return rt->tag = 1, rt->sum = 0, void();
    push_down(rt);
    int mid = (l+r)/2;
    if (L <= mid) clear(L, R, rt->lc, l, mid);
    if (R >  mid) clear(L, R, rt->rc, mid+1, r);
  }
  int query(int L, int R, Node *&rt, int l = -1e9, int r = 1e9) {
    if (!rt) return 0;
    if (l <= L && R >= r) return rt->sum;
    push_down(rt);
    int mid = (l+r)/2;
    if (R <= mid) return query(L, R, rt->lc, l, mid);
    if (L >  mid) return query(L, R, rt->rc, mid+1, r);
    return query(L, R, rt->lc, l, mid)+query(L, R, rt->rc, mid+1, r);
  }
} seg;

int n, m;

inline void solve() {
  cin >> n >> m;
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