#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 1e4+7;

int n, m;
// int w[N], v[N];
int dpv[M], dpn[M];

int main()
{
    while (cin >> m >> n) {
        memset(dpv, 0, sizeof dpv);
        memset(dpn, 0, sizeof dpn);
        for (int i = 1, w, v; i <= n; ++i) {
            cin >> w >> v;
            for (int j = m; j >= w; --j) {
                dpv[j] = max(dpv[j], dpv[j-w]+v);
                dpn[j] = max(dpn[j], dpn[j-w]+1);
            }
        }
        cout << dpv[m] << " " << dpn[m] << endl;
    }
    return 0;
}
