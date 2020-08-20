/*
 * @Author: Kaizyn
 * @Date: 2020-08-14 23:18:40
 * @LastEditTime: 2020-08-15 00:21:04
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

// 0 fire 1 lightning
int n;
long long res;
int cnt[2], sum[2];
set<int> st[2], all1;
set<pii> dob;

inline int get_max() {
  if (st[0].empty() && st[1].empty()) return -1;
  else if (st[0].empty()) return 1;
  else if (st[1].empty()) return 0;
  else return *st[0].rbegin() < *st[1].rbegin();
}

void dinsert(const int &id, int val = 0) {
  if (!val) val = *st[id].rbegin(), st[id].erase(--st[id].end());
  else st[id].erase(st[id].find(val));
  res += val;
  dob.insert({val, id});
}

void derase(int id = -1, int val = 0) {
  if (id == -1) {
    id = dob.begin()->second;
    val = dob.begin()->first;
    dob.erase(dob.begin());
  } else {
    dob.erase(dob.find({val, id}));
  }
  res -= val;
  st[id].insert(val);
}

void modify() {
  int id;
  int sz = max(0, cnt[1]-(cnt[0] == 0));
  while ((int)dob.size() > sz) derase();
  while ((int)dob.size() < sz) dinsert(get_max());
  if (!sz) return;
  while (~(id = get_max()) && dob.begin()->first < *st[id].rbegin()) {
    dinsert(id);
    derase();
  }
  // the smallest lighting can't be doubled
  if (dob.find({*all1.begin(), 1}) != dob.end()) {
    dinsert(get_max());
    derase(1, *all1.begin());
  }
}

void insert(const int &id, const int &val) {
  if (id) all1.insert(val);
  ++cnt[id];
  res += val;
  st[id].insert(val);
  modify();
}

void erase(const int &id, const int &val) {
  if (id) all1.erase(val);
  --cnt[id];
  res -= val;
  if (st[id].find(val) != st[id].end()) st[id].erase(st[id].find(val));
  else dob.erase(dob.find({val, id})), res -= val;
  modify();
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1, tp, d; i <= n; ++i) {
    cin >> tp >> d;
    d > 0 ? insert(tp, d) : erase(tp, -d);
    cout << res << endl;
  }
  return 0;
}