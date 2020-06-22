/*
 * @Author: Kaizyn
 * @Date: 2020-06-17 00:04:11
 * @LastEditTime: 2020-06-17 00:26:10
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

struct DSU {
  int fa[N], num[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i, num[i] = 1; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) {
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    if (num[fx] >= num[fy]) num[fx] += num[fy], fa[fy] = fx;
    else num[fy] += num[fx], fa[fx] = fy;
    return true;
  }
};

int n, k;
int cnt[26];
string s;
// vector<int> vec;
DSU dsu;

inline int solve() {
  cin >> n >> k >> s;
  memset(cnt, 0, sizeof cnt);
  for (const char &c : s) ++cnt[c-'a'];
  sort(cnt, cnt+26);
  reverse(cnt, cnt+26);
  for (int l = n, t, num; l; --l) {
    dsu.init(l);
    // vec.clear();
    for (int i = 0; i < l; ++i) {
      dsu.merge(i, (i+k)%l);
    }
    for (int i = 0; i < l; ++i) if (dsu[i] == i) {
      // vec.emplace_back(dsu.num[i]);
      // cout << dsu.num[i] << endl;
      t = dsu.num[i];
      break;
    }
    num = 0;
    for (int i = 0; i < 26; ++i) num += cnt[i]/t;
    if (num >= l/t) return l;
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}