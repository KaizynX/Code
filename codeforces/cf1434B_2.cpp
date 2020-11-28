/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 19:02:07
 * @LastEditTime: 2020-10-25 20:21:53
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

struct Node {
  int v;
  Node *nex;
  Node(int v = 0) : v(v) { nex = nullptr; }
};

int n;
int a[N], res[N];
Node *head[N], *tail[N];
int q[N], qh, qt;

void insert(int x, int v) {
  if (!tail[x]) {
    head[x] = tail[x] = new Node(v);
  } else {
    tail[x]->nex = new Node(v);
    tail[x] = tail[x]->nex;
  }
}

void merge(int x, int y) { // merge y to x
  if (!head[x]) {
    swap(head[x], head[y]);
    swap(tail[x], tail[y]);
    return;
  }
  if (!head[y]) return;
  tail[x]->nex = head[y];
  tail[x] = tail[y];
  head[y] = tail[y] = nullptr;
}

void erase(int x) {
  head[x] = head[x]->nex;
  if (!head[x]) tail[x] = nullptr;
}

/*
int binary_search(int v) {
  int l = 1, r = top, m;
  while (l < r) {
    m = (l+r)>>1;
    if (stk[m] < v) r = m;
    else l = m+1;
  }
  return l;
}
*/

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
  qh = 1; qt = 0;
  for (int i = 1, j = 0; i <= 2*n; ++i) {
    if (!a[i]) {
      insert(0, ++j);
    } else {
      /*
      if (qh > qt || a[i] < q[qt]) {
        if (!head[0]) return false;
        res[head[0]->v] = a[i];
        erase(0);
      } else {
        while (qh <= qt && a[i] > q[qt]) {
          merge(q[qt], 0);
          --qt;
        }
        auto it = --st.lower_bound(a[i]);
        res[head[*it]->v] = a[i];
        erase(*it);
        if (!head[*it]) st.erase(*it);
      }
      if (head[0]) {
        swap(head[0], head[a[i]]);
        swap(tail[0], tail[a[i]]);
        st.insert(a[i]);
      }
      */
      while (qh <= qt && a[i] > q[qt]) {
        merge(0, q[qt]);
        --qt;
      }
      if (!head[0]) return false;
      res[head[0]->v] = a[i];
      erase(0);
      if (!head[0]) continue;
      swap(head[0], head[a[i]]);
      swap(tail[0], tail[a[i]]);
      q[++qt] = a[i];
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