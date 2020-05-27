/*
 * @Author: Kaizyn
 * @Date: 2020-05-21 14:40:38
 * @LastEditTime: 2020-05-21 15:50:39
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;
const int dir[] = {0,-1,0,1,0};

int n, m;
long long S;
bool a[N*9][N*9], vis[N*9][N*9];
int row[N][3], col[N][3];
vector<int> disx, disy;

inline void add(vector<int> &dis, const int &x) {
  dis.emplace_back(x-1);
  dis.emplace_back(x);
  dis.emplace_back(x+1);
}

inline void discrete() {
  add(disx, 0);
  add(disy, 0);
  for (int i = 1; i <= n; ++i) {
    add(disx, row[i][0]);
    add(disx, row[i][1]);
    add(disy, row[i][2]);
  }
  for (int i = 1; i <= m; ++i) {
    add(disx, col[i][0]);
    add(disy, col[i][1]);
    add(disy, col[i][2]);
  }
  sort(disx.begin(), disx.end());
  disx.erase(unique(disx.begin(), disx.end()), disx.end());
  sort(disy.begin(), disy.end());
  disy.erase(unique(disy.begin(), disy.end()), disy.end());
#define lb(dis,val) val=lower_bound(dis.begin(),dis.end(),val)-dis.begin()
  for (int i = 1; i <= n; ++i) {
    lb(disx, row[i][0]);
    lb(disx, row[i][1]);
    lb(disy, row[i][2]);
  }
  for (int i = 1; i <= m; ++i) {
    lb(disx, col[i][0]);
    lb(disy, col[i][1]);
    lb(disy, col[i][2]);
  }
#undef lb
}

void bfs(const int &sx, const int &sy) {
  static queue<pii> q;
  q.push({sx, sy});
  vis[sx][sy] = 1;
  while (q.size()) {
    int ux = q.front().first;
    int uy = q.front().second;
    if (ux == 0 || uy == 0 || ux == (int)disx.size()-1 ||
        uy == (int)disy.size()-1) {
      cout << "INF" << endl;
      exit(0);
    }
    S += 1ll*(disx[ux]-disx[ux-1])*(disy[uy]-disy[uy-1]);
    q.pop();
    for (int i = 0, vx, vy; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (vx < 0 || vy < 0 || vx >= (int)disx.size() ||
          vy >= (int)disy.size() || a[vx][vy] || vis[vx][vy]) continue;
      vis[vx][vy] = 1;
      q.push({vx, vy});
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> row[i][j];
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> col[i][j];
    }
  }
  discrete();
  for (int i = 1; i <= n; ++i) {
    for (int j = row[i][0]; j <= row[i][1]; ++j) {
      a[j][row[i][2]] = 1;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = col[i][1]; j <= col[i][2]; ++j) {
      a[col[i][0]][j] = 1;
    }
  }
#ifdef DEBUG
  for (int i = 0; i < (int)disx.size(); ++i) {
    for (int j = 0; j < (int)disy.size(); ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
#endif
  bfs(lower_bound(disx.begin(), disx.end(), 0)-disx.begin(),
      lower_bound(disy.begin(), disy.end(), 0)-disy.begin());
  return 0;
}