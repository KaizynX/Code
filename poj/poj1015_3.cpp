#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

const int N = 2e2+7;
const int M = 2e1+7;
const int D = 4e2+27;
const int INF = 1e9;
#ifdef DEBUG
const int V = 20;
#else 
const int V = 4e2;
#endif

int T, n, m;
int mem[N][M][D<<1], path[N][M][D<<1], *dp[N][M];

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
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            dp[i][j] = mem[i][j]+D;

    while (cin >> n >> m && n|m) {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                memset(mem[i][j], -1, sizeof mem[i][j]);
        dp[0][0][0] = 0;

        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 1; k <= i && k <= m && k-1 <= j; ++k) {
                    for (int v = -V; v <= V; ++v) {
                        int last = v-(a[i].p-a[i].d);
                        if (dp[j][k-1][last] == -1) continue;
                        int tmp = dp[j][k-1][last]+a[i].p+a[i].d;
                        if (dp[i][k][v] == -1 || tmp > dp[i][k][v]) {
                            dp[i][k][v] = tmp;
                            path[i][k][v] = j;
                        }
                    }
                }
            }
        }
        int resi = 0, resj = 0, sump = 0, sumd = 0;
        for (int i = m; i <= n; ++i) {
            for (int j = -V; j <= V; ++j) {
                if (dp[i][m][j] == -1) continue;
                if (!resi || abs(j) < abs(resj) ||
                    (abs(j) == abs(resj) && dp[resi][m][resj] < dp[i][m][j])) {
                    resi = i;
                    resj = j;
                }
            }
        }
#ifdef DEBUG
        cout << "res:" << resi << " " << resj << endl;
#endif
        vector<int> choose;
        for (int i = resi, j = resj, k = m; k; --k) {
            choose.push_back(i);
            sump += a[i].p;
            sumd += a[i].d;
            int last = i;
            i = path[i][k][j];
            j -= a[last].p-a[last].d;
        }
        sort(choose.begin(), choose.end());
        cout << "Jury #" << ++T << endl
             << "Best jury has value " << sump
             << " for prosecution and value " << sumd
             << " for defence: " << endl;
        for (int i = 0; i < (int)choose.size(); ++i)
            cout << " " << choose[i];
        cout << endl << endl;
    }
    return 0;
}

