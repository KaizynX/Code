/*
 * @Author: Kaizyn
 * @Date: 2020-07-31 14:02:28
 * @LastEditTime: 2020-07-31 14:27:05
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;

struct Node {
  double t;
  int w;
  Node(const double &_t, const int &_w) : t(_t), w(_w) {}
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.t < rhs.t;
  }
};

int n;
int cnt;
double s[N], m[N], h[N];
vector<Node> tset;

void add(const double &l, const double &r, const int &w = 1) {
  tset.emplace_back(l, w);
  tset.emplace_back(r, -w);
  if (l > r) cnt += w;
}

vector<pdd> overlap(const int &num) {
  double pt = 0;
  vector<pdd> ret;
  sort(tset.begin(), tset.end());
  for (const Node &nd : tset) {
    if (nd.w > 0) {
      if (cnt < num && (cnt+nd.w) >= num) pt = nd.t;
    } else {
      if (cnt >= num && (cnt+nd.w) < num) ret.emplace_back(pt, nd.t);
    }
    cnt += nd.w;
  }
  if (cnt >= num) ret.emplace_back(pt, 360);
  return ret;
}

bool check(const double &err) {
  cnt = 0; tset.clear();
  for (int i = 1; i <= n; ++i) {
    double l = fmod(h[i]-err+360, 360);
    double r = fmod(h[i]+err+360, 360);
    add(l, r);
  }
  vector<pdd> hset = overlap(n);
  if (hset.empty()) return false;

  cnt = 0; tset.clear();
  for (int i = 1; i <= n; ++i) {
    double l = fmod(m[i]-err+360, 360);
    double r = fmod(m[i]+err+360, 360);
    add(l, r);
  }
  vector<pdd> mset = overlap(n);
  if (mset.empty()) return false;

  cnt = 0; tset.clear();
  for (const pdd &pr : mset) add(pr.first, pr.second, n);
  for (const pdd &pr : hset) {
    double l = pr.first, r = pr.second;
    if (r-l >= 30) return true;
    add(fmod(l*12, 360), fmod(r*12, 360));
  }
  return overlap(n+1).size();
}

inline void solve() {
  scanf("%d", &n);
  for (int i = 1, hh, mm, ss; i <= n; ++i) {
    scanf("%d:%d:%d", &hh, &mm, &ss);
    hh %= 12;
    s[i] = ss*6;
    m[i] = mm*6+s[i]/60.0;
    h[i] = hh*30+m[i]/12.0;
  }
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    printf("%.3f %.3f %.3f\n", h[i], m[i], s[i]);
  }
#endif
  double l = 0, r = 180, mid;
  while (r-l > eps) {
    mid = (l+r)/2;
    if (check(mid)) r = mid;
    else l = mid;
  }
  printf("%.10lf\n", r);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}