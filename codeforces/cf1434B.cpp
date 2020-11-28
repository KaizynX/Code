/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 19:02:07
 * @LastEditTime: 2020-10-25 19:59:04
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

int n;
int a[N], res[N];
vector<int> p[N], vec;
set<int> st;

inline bool solve() {
  cin >> n;
  int check = 0;
  for (int i = 1; i <= 2*n; ++i) {
    static char op;
    cin >> op;
    if (op == '+') {
      ++check;
    } else {
      cin >> a[i];
      if (--check < 0) return false;
    }
  }
  if (check) return false;
  for (int i = 1, j = 0; i <= 2*n; ++i) {
    if (!a[i]) {
      vec.push_back(++j);
    } else {
      if (st.empty() || a[i] < *st.begin()) {
        if (vec.empty()) return false;
        res[vec.back()] = a[i];
        vec.pop_back();
      } else {
        // auto it = st.lower_bound(a[i]);
        // if (it == st.begin()) return false;
        // res[p[*--it].back()] = a[i];
        auto it = --st.lower_bound(a[i]);
        res[p[*it].back()] = a[i];

        p[*it].pop_back();
        if (p[*it].empty()) st.erase(*it);
      }
      if (vec.size()) {
        swap(p[a[i]], vec);
        st.insert(a[i]);
      }
    }
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    if (solve()) {
      cout << "YES\n";
      for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}