/*
 * @Author: Kaizyn
 * @Date: 2020-05-21 14:40:38
 * @LastEditTime: 2020-05-21 16:35:09
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
bool a[N*6][N*6], vis[N*6][N*6];
int row[N][3], col[N][3];
vector<int> disx, disy;

inline void discrete() {
  disx.emplace_back(0);
  disy.emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    disx.emplace_back(row[i][0]);
    disx.emplace_back(row[i][1]);
    disy.emplace_back(row[i][2]);
  }
  for (int i = 1; i <= m; ++i) {
    disx.emplace_back(col[i][0]);
    disy.emplace_back(col[i][1]);
    disy.emplace_back(col[i][2]);
  }
  sort(disx.begin(), disx.end());
  sort(disy.begin(), disy.end());
  disx.erase(unique(disx.begin(), disx.end()), disx.end());
  disy.erase(unique(disy.begin(), disy.end()), disy.end());
#define lb(dis,val) val=(lower_bound(dis.begin(),dis.end(),val)-dis.begin())*2
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

inline long long calc(const int &x, const int &y) {
  long long h = x&1 ? disx[x/2+1]-disx[x/2] : 0;
  long long w = y&1 ? disy[y/2+1]-disy[y/2] : 0;
  return h*w;
}

void bfs(const int &sx, const int &sy) {
  static queue<pii> q;
  q.push({sx, sy});
  vis[sx][sy] = 1;
  while (q.size()) {
    int ux = q.front().first;
    int uy = q.front().second;
    if (ux == 0 || uy == 0 || ux == n-1 || uy == m-1) {
      cout << "INF" << endl;
      exit(0);
    }
    S += calc(ux, uy);
    q.pop();
    for (int i = 0, vx, vy; i < 4; ++i) {
      vx = ux+dir[i];
      vy = uy+dir[i+1];
      if (vx < 0 || vy < 0 || vx >= n || vy >= m ||
          a[vx][vy] || vis[vx][vy]) continue;
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
  n = disx.size()*2-1;
  m = disy.size()*2-1;
#ifdef DEBUG
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
#endif
  bfs((lower_bound(disx.begin(), disx.end(), 0)-disx.begin())*2,
      (lower_bound(disy.begin(), disy.end(), 0)-disy.begin())*2);
  cout << S << endl;
  return 0;
}