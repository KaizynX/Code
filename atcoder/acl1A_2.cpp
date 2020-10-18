/*
 * @Author: Kaizyn
 * @Date: 2020-10-04 19:53:49
 * @LastEditTime: 2020-10-04 20:25:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

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

int n;
pair<int, int> a[N];
int yid[N];
DSU dsu;
set<int> st;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    a[i] = {x, y};
    yid[y] = i;
  }
  dsu.init(n);
  sort(a+1, a+n+1);
  st.clear();
  for (int i = 1, y; i <= n; ++i) {
    y = a[i].second;
    auto it = st.lower_bound(y);
    if (it != st.begin()) dsu.merge(yid[y], yid[*(--it)]);
    st.insert(y);
  }
  st.clear();
  for (int i = n, y; i; --i) {
    y = a[i].second;
    auto it = st.upper_bound(y);
    if (it != st.end()) dsu.merge(yid[y], yid[*it]);
    st.insert(y);
  }
  for (int i = 1; i <= n; ++i) cout << dsu.num[dsu[i]] << endl;
  return 0;
}