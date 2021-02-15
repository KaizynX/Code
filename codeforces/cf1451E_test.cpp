/*
 * @Author: Kaizyn
 * @Date: 2021-02-14 14:16:22
 * @LastEditTime: 2021-02-14 16:08:46
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = (1<<16)+7;

int n;
int a[233][233], tmp[233], res[N];
int mp[N];

inline void init() {
#ifdef DEBUG
  cout << "    ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << i << j << k << " ";
  }
  cout << "\n1&2 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (i&j) << ' ';
  }
  cout << "\n1&3 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (i&k) << ' ';
  }
  cout << "\n1|2 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (i|j) << ' ';
  }
  cout << "\n1|3 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (i|k) << ' ';
  }
  cout << "\n1^2 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (i^j) << ' ';
  }
  cout << "\n1^3 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (i^k) << ' ';
  }
  cout << "\n2&3 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (j&k) << ' ';
  }
  cout << "\n2|3 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (j|k) << ' ';
  }
  cout << "\n2^3 ";
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    cout << "  " << (j^k) << ' ';
  }
  cout << '\n';
#endif
/*
    000 001 010 011 100 101 110 111
1&2   0   0   0   0   0   0   1   1
1&3   0   0   0   0   0   1   0   1
1|2   0   0   1   1   1   1   1   1
1|3   0   1   0   1   1   1   1   1
1^2   0   0   1   1   1   1   0   0
1^3   0   1   0   1   1   0   1   0
2&3   0   0   0   1   0   0   0   1
2|3   0   1   1   1   0   1   1   1
2^3   0   1   1   0   0   1   1   0
*/
  for (int i = 0; i < 8; ++i) {
    int i1 = (i>>2)&1, i2 = (i>>1)&1, i3 = i&1;
    a[i][0] = i1&i2;
    a[i][1] = i1&i3;
    a[i][2] = i1|i2;
    a[i][3] = i1|i3;
    a[i][4] = i1^i2;
    a[i][5] = i1^i3;
    a[i][6] = i2&i3;
    a[i][7] = i2|i3;
    a[i][8] = i2^i3;
  }
  /*
  set<int> vis;
  for (int b = 0; b < 1<<9; ++b) {
    if (__builtin_popcount(b) != 5) continue;
    vis.clear();
    for (int i = 0; i < 8; ++i) {
      int val = 0;
      for (int j = 0, k = 0; j < 9; ++j) if ((b>>j)&1) {
        val += a[i][j]<<(k++);
      }
      mp[val] = i;
      vis.insert(val);
    }
    if (vis.size() == 8) {
#ifdef DEBUG
      cout << bitset<9>(b) << endl; // 001001111
      cout << b << endl; // 79
      for (int i : vis) cout << mp[i] << " " << i << '\n';
#endif
      break;
    }
  }
  */
  set<int> vis;
  for (int b = 0; b < 1<<9; ++b) {
    if (__builtin_popcount(b) != 5) continue;
    if (~b&(1<<4)) continue;
    if (~b&(1<<5)) continue;
    if (~b&(1<<8)) continue;
    vis.clear();
    for (int i = 0; i < 8; ++i) {
      int val = 0;
      for (int j = 0, k = 0; j < 9; ++j) if ((b>>j)&1) {
        val += a[i][j]<<(k++);
      }
      mp[val] = i;
      vis.insert(val);
    }
    if (vis.size() == 8) {
#ifdef DEBUG
      cout << bitset<9>(b) << endl; // 001001111
      cout << b << endl; // 79
#endif
      break;
    }
  }
  /*
  set<int> vis;
  for (int b = 0; b < 1<<6; ++b) {
    if (__builtin_popcount(b) != 4) continue;
    int flag = 1;
    vis.clear();
    for (int i = 0; i < 4; ++i) {
      int val = 0;
      for (int j = 0, k = 0; j < 6; ++j) if ((b>>j)&1) {
        val += a[i][j]<<(k++);
      }
      mp[val] = 0;
      vis.insert(val);
    }
    for (int i = 4; i < 8; ++i) {
      int val = 0;
      for (int j = 0, k = 0; j < 6; ++j) if ((b>>j)&1) {
        val += a[i][j]<<(k++);
      }
      mp[val] = 1;
      if (vis.count(val)) flag = 0;
    }
    if (flag) {
#ifdef DEBUG
      cout << bitset<6>(b) << endl; // 011001
      cout << b << endl; // 25
      for (int i = 0; i < 8; ++i) cout << mp[i] << " \n"[i==7];
#endif
      break;
    }
  }
  */
  /*
  set<int> vis;
  for (int b = 0; b < 1<<9; ++b) {
    if (__builtin_popcount(b) != 5) continue;
    if (~b&(1<<4)) continue;
    if (~b&(1<<5)) continue;
    if (~b&(1<<8)) continue;
    int flag = 1;
    vis.clear();
    for (int i = 0; i < 4; ++i) {
      int val = 0;
      for (int j = 0, k = 0; j < 9; ++j) if ((b>>j)&1) {
        val += a[i][j]<<(k++);
      }
      mp[val] = 0;
      vis.insert(val);
    }
    for (int i = 4; i < 8; ++i) {
      int val = 0;
      for (int j = 0, k = 0; j < 9; ++j) if ((b>>j)&1) {
        val += a[i][j]<<(k++);
      }
      mp[val] = 1;
      if (vis.count(val)) flag = 0;
    }
    if (flag) {
#ifdef DEBUG
      cout << bitset<9>(b) << endl; // 01001101
      cout << b << endl; // 77
      // for (int i = 0; i < 8; ++i) cout << mp[i] << " \n"[i==7];
#endif
      break;
    }
  }
  */
}

int query(string q, int x, int y) {
  cout << q << " " << x << " " << y << endl;
  cin >> x;
  return x;
}

void answer() {
  cout << "!";
  for (int i = 1; i <= n; ++i) cout << " " << res[i];
  cout << endl;
}

inline void solve() {
  init();
  cin >> n;
  /*
  tmp[1] = query("AND", 1, 3);
  tmp[2] = query("OR", 1, 2);
  tmp[4] = query("XOR", 1, 2);
  tmp[5] = query("XOR", 1 ,3);
  */
  tmp[0] = query("AND", 1, 2);
  tmp[1] = query("AND", 1, 3);
  tmp[2] = query("OR", 1, 2);
  tmp[3] = query("OR", 1, 3);
  tmp[6] = query("AND", 2 ,3);
  for (int b = 0; 1<<b < n; ++b) {
    int val = (((tmp[0]>>b)&1)<<0)+
              (((tmp[1]>>b)&1)<<1)+
              (((tmp[2]>>b)&1)<<2)+
              (((tmp[3]>>b)&1)<<3)+
              (((tmp[6]>>b)&1)<<4);
#ifdef DEBUG
    cout << val << " " << mp[val] << "\n";
#endif
    val = mp[val];
    res[1] |= ((val>>2)&1)<<b;
    res[2] |= ((val>>1)&1)<<b;
    res[3] |= ((val>>0)&1)<<b;
  }
#ifndef DEBUG
  for (int i = 4; i <= n; ++i) {
    res[i] = query("XOR", 1, i)^res[1];
  }
#endif
  answer();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
4
0 1 3 3 2
*/