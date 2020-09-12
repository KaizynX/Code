/*
 * @Author: Kaizyn
 * @Date: 2020-09-07 19:59:32
 * @LastEditTime: 2020-09-07 20:56:01
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e3+7;

struct Node {
  int v, t;
  int l, r;
  Node(int _v = 0, int _t = 0) : v(_v), t(_t) { l = r = 0; }
};

int n, q, tot, head = 1;
string s;
Node lt[N<<1];

int insert(int x, int v, int t = 1) {
  if (!t) return x;
  lt[++tot] = Node(v, t);
  lt[tot].l = x;
  lt[tot].r = lt[x].r;
  lt[lt[x].r].l = tot;
  lt[x].r = tot;
  return tot;
}

void erase(int x) {
  int l = lt[x].l, r = lt[x].r;
  lt[l].r = r;
  lt[r].l = l;
}

void add(int x, string s) {
  #ifdef DEBUG
  cout << "add:" << s << endl;
  #endif
  int val = 0, sum = 1<<s.size();
  for (char &c : s) val = val*2+c-'0';
  x = insert(x, 0, sum-val-1);
  x = insert(x, 1);
  x = insert(x, 0, val);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> q >> s;
  for (char &c : s) insert(tot, c-'0');
  insert(tot, 0, 1);
  // 0 head tot tail
  for (int _ = 1, l, r; _ <= q; ++_) {
    cin >> l >> r;
    int i = 0, p = 0, st;
    while (p+lt[i].t < l) {
      p += lt[i].t;
      st = i;
      i = lt[i].r;
    }
    s = "";
    while (p <= r) {
      erase(i);
      st = insert(st, lt[i].v, max(0, l-p-1));
      s += string(min(r, p+lt[i].t)-max(l-1, p) ,lt[i].v+'0');
      p += lt[i].t;
      // s += string(lt[i].v+'0', min(r, p)-max(l-1, p));
      if (p >= r) {
        insert(st, lt[i].v, p-r);
        break;
      }
      i = lt[i].r;
    }
    add(st, s);
  }
  int cnt = 0, p = 0, i = lt[0].r;
  while (i) {
    cnt += lt[i].v;
    p += lt[i].t;
    i = lt[i].r;
  }
  cout << cnt << endl;
  p = 0; i = lt[0].r;
  while (i) {
    if (lt[i].v) cout << p+1 << " ";
    p += lt[i].t;
    i = lt[i].r;
  }
  cout << endl;
  return 0;
}