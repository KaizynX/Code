#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e2+7;
const int M = 2e1+7;
const int D = 5e2+7;
const int INF = 1e9;
#ifdef DEBUG
const int V = 10;
#else 
const int V = 4e2;
#endif

int T, n, m;
int mem[M][D<<1], *dp[M];
vector<int> path[M][D<<1];

struct Node
{
    int d, p;
    friend istream &operator >> (istream &is, Node &x) {
        return is >> x.p >> x.d;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < M; ++i) dp[i] = mem[i]+D;
    while (cin >> n >> m && n|m) {
        memset(mem, -1, sizeof mem);
        dp[0][0] = 0;
        path[0][0].clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            for (int j = min(m, i); j; --j) {
                for (int v = -V; v <= V; ++v) {
                    int last = v-(a[i].p-a[i].d);
                    if (dp[j-1][last] == -1) continue;
                    int tmp = dp[j-1][last]+a[i].p+a[i].d;
                    if (dp[j][v] == -1 || tmp > dp[j][v]) {
                        dp[j][v] = tmp;
                        path[j][v] = path[j-1][last];
                        path[j][v].push_back(i);
                    }
                }
            }
        }
        int resi, sump = 0, sumd = 0;
        for (int i = 0; i <= V; ++i) {
            if (dp[m][i] == -1 && dp[m][-i] == -1) continue;
            if (dp[m][i] == -1) resi = -i;
            else if (dp[m][-i] == -1) resi = i;
            else resi = dp[m][i] >= dp[m][-i] ? i : -i;
            break;
        }
#ifdef DEBUG
        cout << "DEBUG:" << resi << " " << dp[m][resi] << endl;
#endif
        for(int i = 0; i < (int)path[m][resi].size(); ++i) {
            int cur = path[m][resi][i];
            sump += a[cur].p;
            sumd += a[cur].d;
        }
        cout << "Jury #" << ++T << endl
             << "Best jury has value " << sump
             << " for prosecution and value " << sumd
             << " for defence: " << endl;
        for (int i = 0; i < (int)path[m][resi].size(); ++i)
            cout << " " << path[m][resi][i];
        cout << endl << endl;
    }
    return 0;
}

