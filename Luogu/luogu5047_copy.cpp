#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
typedef long long ll;
#define lwb lower_bound
#define il inline
#define DEBUG
int n, m, B, L, V;
int base[N], tmp[N], bl[N], blv[N], _bit[N];
ll sumb[N], sump[N], res[N], ans[N], s1[N], s2[N];

vector< tuple<int, int, int> > ql[N], qr[N] ;

struct query{ int id, l, r ;} q[N] ;

il bool comp(const query &a, const query &b){
	return (bl[a.l] ^ bl[b.l]) ? bl[a.l] < bl[b.l] : 
		   ((bl[a.l] & 1) ? a.r < b.r : a.r > b.r) ;
}
il int ask(int p){
    int ret = 0 ;
    for ( ; p ; p -= p & -p) ret += _bit[p] ;
    return ret ;
}
il void add(int p){
    for ( ; p <= V ; p += p & -p) _bit[p] ++ ;
}
il void Inssuf(const int &x){
    for (int i = blv[x] + 1 ; i <= blv[V] ; ++ i) sumb[i] ++ ;
    for (int i = x ; blv[x] == blv[i] && i <= V ; ++ i) sump[i] ++ ;
}
il int Asksuf(const int &x){
    return sump[x] + sumb[blv[x]] ;
}
il void Inspre(const int &x){
    for (int i = 1 ; i <= blv[x] - 1 ; ++ i) sumb[i] ++ ;
    for (int i = x ; blv[x] == blv[i] && i >= 1 ; -- i) sump[i] ++ ;
}
il int Askpre(const int &x){
    return sump[x] + sumb[blv[x]] ;
}
int main(){
	cin >> n >> m;
   B = n / sqrt(m) ;
	for (int i = 1 ; i <= n ; ++ i)
        cin >> base[i], tmp[i] = base[i] ;
    sort(tmp + 1, tmp + n + 1) ;
    L = unique(tmp + 1, tmp + n + 1) - tmp - 1 ;
    for (int i = 1 ; i <= n ; ++ i){
        base[i] = lwb(tmp + 1, tmp + L + 1, base[i]) - tmp ;
        V = max(base[i], V) ; bl[i] = i / B ;
    }
    B = sqrt(V) + 1 ;
    for (int i = 0 ; i <= V ; ++ i) blv[i] = i / B + 1 ;
    for (int i = n ; i >= 1 ; -- i)
        s2[i] = s2[i + 1] + ask(base[i] - 1), add(base[i]) ;
    fill(_bit, _bit + V + 1, 0) ;
    for (int i = 1 ; i <= n ; ++ i) {
        s1[i] = s1[i - 1] + i - 1 - ask(base[i]);
        add(base[i]) ;
    }
	for (int i = 1 ; i <= m ; ++ i)
		cin >> q[i].l >> q[i].r, q[i].id = i ;
	sort(q + 1, q + m + 1, comp) ; q[0].l = 1, q[0].r = 0 ;
	for (int i = 1 ; i <= m ; ++ i){
		int newl = q[i].l ;
		int newr = q[i].r ;
		int l = q[i - 1].l ;
		int r = q[i - 1].r ;
		ans[i] -= s2[l] + s1[r] ;//l 的贡献变成了一个后缀，原来是 l'-(l-1),现在变成了 l-l'
		ans[i] += s2[newl] + s1[newr] ;//l 和 r 要分开计算贡献
		if (newl < l)
			qr[newr + 1].emplace_back(newl, l - 1, -i) ;
		else if (newl > l)
			qr[newr + 1].emplace_back(l, newl - 1, i) ;
		if (newr < r)
			ql[l - 1].emplace_back(newr + 1, r, i) ;
		else if (newr > r)
			ql[l - 1].emplace_back(r + 1, newr, -i) ;
	}
  #ifdef DEBUG
  cout << "s1:";
  for (int i = 1; i <= n; ++i) cout << s1[i] << " \n"[i==n];
  cout << "s2:";
  for (int i = 1; i <= n; ++i) cout << s2[i] << " \n"[i==n];
  cout << "ans:";
  for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i==m];
  cout << "***********" << endl;
  #endif
	for (int i = 1 ; i <= n ; ++ i){
        Inspre(base[i]) ;
		for (const auto &j : ql[i]){
			int l, r, id ;
			tie(l, r, id) = j ; ll tmp = 0 ;
			for (int o = l ; o <= r ; ++ o)
                tmp += Askpre(base[o] + 1) ;
			if (id < 0)
                ans[id * (-1)] -= tmp ;
            else ans[id] += tmp ;
      #ifdef DEBUG
      printf("%d (%d %d %d) %lld\n", i, id, l, r, ans[id]);
      #endif
		}
	}
  #ifdef DEBUG
  cout << "ans:";
  for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i==m];
  #endif
    memset(sumb, 0, sizeof(sumb)) ;
    memset(sump, 0, sizeof(sump)) ;
    for (int i = n ; i >= 1 ; -- i){
        Inssuf(base[i]) ;
		for (const auto &j : qr[i]){
			int l, r, id ;
			tie(l, r, id) = j ; ll tmp = 0 ;
			for (int o = l ; o <= r ; ++ o)
                tmp += Asksuf(base[o] - 1) ;
			if (id < 0)
                ans[id * (-1)] -= tmp ;
            else ans[id] += tmp ;
		}
    }
  #ifdef DEBUG
  cout << "ans:";
  for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i==m];
  #endif
	for (int i = 1 ; i <= m ; ++ i) ans[i] += ans[i - 1] ;
	for (int i = 1 ; i <= m ; ++ i) res[q[i].id] = ans[i] ; 
  for (int i = 1; i <= m; ++i) cout << res[i] << endl;
  return 0 ;
}