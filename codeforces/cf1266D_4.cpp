#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 3e5+7;

int n, m;
long long in[N], ot[N], du[N];
vector<int> resi, resj;
vector<long long> resp;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, u, v, d; i <= m; ++i) {
        cin >> u >> v >> d;
        if (u == v) continue;
        in[v] += d;
        ot[u] += d;
    }
    for (int i = 1; i <= n; ++i) du[i] = ot[i]-in[i];
    int l = 1, r = n;
    while (l <= n && r >= 1) {
        while (l <= n && du[l] <= 0) ++l;
        while (r >= 1 && du[r] >= 0) --r;
        if (l > n || r < 1) break;
        long long tmp = min(du[l], -du[r]);
        du[l] -= tmp;
        du[r] += tmp;
        resi.emplace_back(l);
        resj.emplace_back(r);
        resp.emplace_back(tmp);
    }
    cout << resi.size() << endl;
    for (int i = 0; i < (int)resi.size(); ++i)
        cout << resi[i] << " " << resj[i] << " " << resp[i] << endl;
    return 0;
}
