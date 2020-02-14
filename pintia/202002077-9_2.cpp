#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m, k;
int par[N], enm[N];

int getp(int x) { return par[x] == x ? x : par[x] = getp(par[x]); }

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1, x, y, w, fx, fy, ex, ey; i <= m; ++i) {
        cin >> y >> x >> w;
        fx = getp(x); fy = getp(y);
        if (w == 1) {
            if (fx != fy) par[fx] = fy;
            continue;
        }
        ex = enm[x]; ey = enm[y];
        if(!ex && !ey) {
			enm[x] = y;
			enm[y] = x;
		}
		else if(!ex && ey) {
			par[x] = getp(ey);
			enm[x] = getp(y);
		}
		else if(ex && !ey) {
			par[y] = getp(ex);
			enm[y] = getp(x);
		}
		else if(getp(ex) != getp(ey)) {
			par[getp(y)] = getp(ex);
			par[getp(x)] = getp(ey);
		}
    }
    for (int i = 1, x, y, fx, fy, ex, ey, f1, f2; i <= k; ++i) {
        cin >> x >> y;
        fx = getp(x); fy = getp(y);
        ex = getp(enm[x]); ey = getp(enm[y]);
        f1 = fx == fy;
        f2 = ex == fy || ey == fx;
        if (f1 && f2) cout << "OK but...\n";
        else if (f1) cout << "No problem\n";
        else if (f2) cout << "No way\n";
        else cout << "OK\n";
    }
    return 0;
}
