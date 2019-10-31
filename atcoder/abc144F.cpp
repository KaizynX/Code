#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 600+7;
const int M = N*N/2;

int n, m;
int s[M], t[M], pre_len[N][N], pre_num[N][N], bac_len[N][N], bac_num[N][N];
vector<int> ind[N], otd[N];
double res;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> s[i] >> t[i];
        ind[t[i]].push_back(s[i]);
        otd[s[i]].push_back(t[i]);
    }
    for (int i : otd[1]) {
        pre_len[1][i] = pre_num[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j : ind[i]) {
            for (int k : ind[j]) {
                pre_len[j][i] += pre_len[k][j]+1;
                pre_num[j][i] += pre_num[k][j];
            }
        }
    }
    for (int i : ind[n]) {
        bac_len[i][n] = bac_num[i][n] = 1;
    }
    for (int i = n-1; i; --i) {
        for (int j : otd[i]) {
            for (int k : otd[j]) {
                bac_len[i][j] += bac_len[j][k]+1;
                bac_num[i][j] += bac_num[j][k];
            }
        }
    }

    int sum_len = 0, sum_num = 0;
    for (int i : otd[1]) {
        sum_len += bac_len[1][i];
        sum_num += bac_num[1][i];
    }
    res = 1.0*sum_len/sum_num;

    for (int i = 1; i <= m; ++i) {
        int pl = 0, pn = 0, bl = 0, bn = 0;
        pl = pre_len[s[i]][t[i]]+pre_num[s[i]][t[i]]*bac_len[s[i]][t[i]];
        bl = bac_len[s[i]][t[i]]+bac_num[s[i]][t[i]]*pre_len[s[i]][t[i]];
        pn = pre_num[s[i]][t[i]]*bac_num[s[i]][t[i]];
        // assert(pl == bl);
#ifdef DEBUG
        cout << endl << i << " " << s[i] << " " << t[i] << endl
             << pre_len[s[i]][t[i]] << " " << pre_num[s[i]][t[i]] << endl
             << bac_len[s[i]][t[i]] << " " << bac_num[s[i]][t[i]] << endl;
#endif
        if (pn == sum_num) continue;
        res = min(res, 1.0*(sum_len-pl)/(sum_num-pn));
    }
    cout << res << endl;
    return 0;
}
