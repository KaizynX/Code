#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;

int n;
int x[N], y[N];
int par[N], enm[N];
long long dis[N][N];

int getp(int s) { return par[s] == s ? s : par[s] = getp(par[s]); }

inline void print()
{
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        if (getp(i) == 1) res.emplace_back(i);
    }
    cout << res.size() << endl;
    for (int i : res) cout << i << " ";
    cout << endl;
}

inline void solve(int x)
{
    int flag = 1;
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1, ei, ej; i <= n; ++i) {
        for (int j = 1; j < i; ++j) if (dis[i][j] == x) {
            if (getp(i) == getp(j)) {
                flag = 0;
                break;
            }
            ei = enm[i];
            ej = enm[j];
            if (!ei && !ej) {
                enm[i] = j;
                enm[j] = i;
            } else if (!ei && ej) {
                par[i] = getp(ej);
                enm[i] = getp(j);
            } else if (ei && !ej) {
                par[j] = getp(ei);
                enm[j] = getp(i);
            } else if (getp(ei) != getp(ej)) {
                par[getp(j)] = getp(i);
                par[getp(i)] = getp(j);
            }
        }
        if (!flag) break;
    }
    if (flag) {
        print();
        exit(0);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];
    set<long long> tmp;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            dis[i][j] = dis[j][i] = 1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]);
            tmp.insert(dis[i][j]);
        }
    }
#ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
#endif
    if (tmp.size() == 1) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = dis[i][j] == *tmp.begin() ? 1 : 0;

    solve(0);
    solve(1);
    return 0;
}
