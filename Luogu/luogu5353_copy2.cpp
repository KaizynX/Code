/*
 * @Author: Kaizyn
 * @Date: 2021-08-04 22:35:09
 * @LastEditTime: 2021-08-04 23:31:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

int n;
int a[N], d[N], f[N][20];
vector<int> e[N];

void dfs(int u = 1, int fa = 0) {
  d[u] = d[fa]+1;
  f[u][0] = fa;
  for (int i = 1; (1<<i) <= d[u]; ++i)
    f[u][i] = f[f[u][i-1]][i-1];
  for (auto v : e[u]) if (v != fa)
    dfs(v, u);
}
void rsort(int m,int one[],int two[],int res[])
{
    static int buk[N], i;
    for(i=1; i<=n; ++i) ++buk[one[i]];
    for(i=1; i<=m; ++i) buk[i]+=buk[i-1];
    for(i=n; i>=1; --i) res[buk[one[two[i]]]--]=two[i];
    for(i=0; i<=m; ++i) buk[i]=0;
}
int fa[N];
char s[N];
int sa[N],_rk[N],_tp[N];
auto rk=_rk,tp=_tp;
int rk2[N],st[N];
void solve()
{
    int i,w,p;
    for(i=1; i<=n; ++i) rk[i]=s[i],tp[i]=i;
    rsort(128,rk,tp,sa);
    for(i=1; i<=n; ++i) rk2[sa[i]]=i;
    for(w=1,p=0; w<n&&p<n; w<<=1)
    {
        for(i=1; i<=n; ++i) st[i]=rk2[fa[i]];
        // for (int i = 1; i <= n; ++i) cout << fa[i] << " \n"[i==n];
        // for (int i = 1; i <= n; ++i) cout << st[i] << " \n"[i==n];
        rsort(n,st,sa,tp);
        rsort(w==1?128:p,rk,tp,sa);
        swap(rk,tp);
        rk2[sa[1]]=rk[sa[1]]=p=1;
        for(i=2; i<=n; ++i)
        {
            rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[fa[sa[i]]]==tp[fa[sa[i-1]]])?p:++p;
            rk2[sa[i]]=i;
        }
        bool hv=0;
        for(i=n; i>=1; --i) fa[i]=fa[fa[i]],hv|=fa[i];
        if(!hv) break;
    }
}


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 2; i <= n; ++i) cin >> fa[i];
  cin >> (s+1);
  solve();
  for (int i = 1; i <= n; ++i) cout << sa[i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << rk[i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << rk2[i] << " \n"[i==n];
  return 0;
}