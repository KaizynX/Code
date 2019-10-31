#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 600+7;
const int M = N*N/2;

int n, m;
int s[M], t[M], pre_len[N], pre_num[N], bac_len[N], bac_num[N];
vector<int> ind[N], otd[N];
double res;

int main()
{
    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        // cin >> s[i] >> t[i];
        scanf("%d %d", s+i, t+i);
        ind[t[i]].push_back(s[i]);
        otd[s[i]].push_back(t[i]);
    }
    pre_num[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j : ind[i]) {
            pre_len[i] += pre_len[j]+pre_num[j];
            pre_num[i] += pre_num[j];
        }
    }
    bac_num[n] = 1;
    for (int i = n-1; i; --i) {
        for (int j : otd[i]) {
            bac_len[i] += bac_len[j]+bac_num[j];
            bac_num[i] += bac_num[j];
        }
    }

#ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        cout << endl << i << endl
             << pre_len[i] << " " << pre_num[i] << endl
             << bac_len[i] << " " << bac_num[i] << endl;
    }
    int resi = 0;
#endif

    res = 1.0*bac_len[1]/bac_num[1];
    for (int i = 1; i <= m; ++i) {
        int num = pre_num[s[i]]*bac_num[t[i]],
            // len = pre_len[s[i]]+pre_num[s[i]]*bac_len[t[i]]+num;
            len = bac_num[t[i]]*pre_len[s[i]]+pre_num[s[i]]*bac_len[t[i]]+num;
        if (num == bac_num[1]) continue;
        double now = 1.0*(bac_len[1]-len)/(bac_num[1]-num);
#ifdef DEBUG
        printf("%d->%d %lf\n", s[i], t[i], now);
#endif
        if (now < res) {
            res = now;
#ifdef DEBUG
            resi = i;
#endif
        }
    }
    // cout << res << endl;
    printf("%.10lf\n", res);
#ifdef DEBUG
    printf("%d->%d\n", s[resi], t[resi]);
#endif
    return 0;
}
