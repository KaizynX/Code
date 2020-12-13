#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

struct Node {
  string name, id;
  int status, h, m, order;
  friend istream& operator >>(istream &is, Node &nd) {
    static char c;
    return is >> nd.name >> nd.id >> nd.status >> nd.h >> c >> nd.m;
    // scanf("%d:%d", &nd.h, &nd.m);
    // return is;
  }
  friend ostream& operator <<(ostream &os, Node &nd) {
    return os << nd.name << " " << nd.id;
  }
  bool operator <(const Node &nd) const {
    return id < nd.id;
    // if (name != nd.name) return name < nd.name;
    // if (id != nd.id) return id < nd.id;
    // return false;
  }
  bool check() {
    if (id.size() != 18) return false;
    for (char &c : id) if (!isdigit(c)) return false;
    return true;
  }
};

int D, P, T, S;
Node a[N];
map<Node, int> mp, vis;
vector<Node> output;

signed main() {
  cin >> D >> P;
  for (int d = 1; d <= D; ++d) {
    cin >> T >> S;
    for (int i = 1; i <= T; ++i) {
      cin >> a[i];
      a[i].order = i;
    }
    sort(a+1, a+T+1, [](Node &x, Node &y) {
      return x.h*60+x.m == y.h*60+y.m ? x.order < y.order : x.h*60+x.m < y.h*60+y.m;
    });
    for (int i = 1; i <= T && S; ++i) {
      if (!a[i].check()) continue;
      if (a[i].status && mp.count(a[i]) && !vis.count(a[i])) {
        vis[a[i]] = 1;
        output.emplace_back(a[i]);
      }
      if (mp.count(a[i]) && mp[a[i]]+P+1 > d) continue;
      mp[a[i]] = d;
      cout << a[i] << endl;
      --S;
    }
  }
  for (auto &o : output) cout << o << endl;
  return 0;
}