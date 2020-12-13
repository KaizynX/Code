#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5+7;
typedef pair<int, int> pii;

int n, q;
long long s;
set<pii> up[N], dw[N];

signed main() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    s += i*i;
    up[i].insert({0, i});
    up[i].insert({1e9, i});
    dw[i].insert({0, i});
    dw[i].insert({1e9, i});
  }
  for (int i = 1, x1, x2, y, u1, u2, d1, d2; i <= q; ++i) {
    char op;
    cin >> op >> x1 >> x2 >> y;
    if (op == '+') {
      u1 = (--up[x1].upper_bound({y, 0}))->second;
      u2 = (--up[x2].upper_bound({y, 0}))->second;
      d1 = dw[x1].upper_bound({y, 0})->second;
      d2 = dw[x2].upper_bound({y, 0})->second;
      s += d1*u2+d2*u1-d1*u1-d2*u2;
      up[x1].insert({y, u2});
      up[x2].insert({y, u1});
      dw[x1].insert({y, d2});
      dw[x2].insert({y, d1});
    } else {
      auto itd = dw[x1].upper_bound({y, 0});
      auto itu = up[x1].upper_bound({y, 0});
      s -= itu->second*(++itd)->second;
      s += (--itu)->second*itd->second;
      itd = dw[x2].upper_bound({y, 0});
      itu = up[x2].upper_bound({y, 0});
      s -= itu->second*(++itd)->second;
      s += (--itu)->second*itd->second;
      up[x1].erase(up[x1].upper_bound({y, 0}));
      up[x2].erase(up[x2].upper_bound({y, 0}));
      dw[x1].erase(dw[x1].upper_bound({y, 0}));
      dw[x2].erase(dw[x2].upper_bound({y, 0}));
    }
    // printf("u1:%lld, d1:%lld, u2:%lld, d2:%lld\n", u1, d1, u2, d2);
    cout << s << endl;
  }
  return 0;
}