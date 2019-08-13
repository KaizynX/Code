#include <bits/stdc++.h>

using namespace std;

const int kN = 2e3+7;

int n, k, res;
int mmp[kN][kN];
int row_sum[kN][kN], row_can[kN][kN];
int col_sum[kN][kN], col_can[kN][kN];

int main()
{
    cin >> n >> k;
    string buf;
    for(int i = 1; i <= n; ++i) {
        cin >> buf;
        for(int j = 0; j < n; ++j) 
            mmp[i][j+1] = (buf[j] == 'B' ? 1 : 0);
    }
    for(int i = 1; i <= n; ++i) {
        int l = n+1, r = 0, cnt = 0;
        for(int j = 1; j <= n; ++j) {
            if (mmp[i][j]) {
                ++cnt;
                l = min(l, j);
                r = max(r, j);
            }
            // row_can[i][j] = row_can[i-1][j];
        }
        // row_sum[i] = row_sum[i-1];
        if (!cnt) ++res;
        if (!cnt || r-l+1 > k) continue;
        // ++row_sum[i];
        for(int j = max(1, r-k+1); j <= l; ++j)
            ++row_can[i][j];
    }
    for(int j = 1; j <= n; ++j) {
        for(int i = 1; i <= n; ++i) {
            row_sum[i][j] = row_sum[i-1][j]+row_can[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        int l = n+1, r = 0, cnt = 0;
        for(int j = 1; j <= n; ++j) {
            if (mmp[j][i]) {
                ++cnt;
                l = min(l, j);
                r = max(r, j);
            }
            // col_can[j][i] = col_can[j][i-1];
        }
        // col_sum[i] = col_sum[i-1];
        if (!cnt) ++res;
        if (!cnt || cnt > k) continue;
        // ++col_sum[i];
        for(int j = max(1, r-k+1); j <= l; ++j)
            ++col_can[j][i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            col_sum[i][j] = col_sum[i][j-1]+col_can[i][j];
        }
    }
    int tmp = 0;
    for(int i = 1; i <= n-k+1; ++i) {
        for(int j = 1; j <= n-k+1; ++j) {
            int now = 0;
            now += row_sum[i+k-1][j]-row_sum[i-1][j];
            now += col_sum[i][j+k-1]-col_sum[i][j-1];
            tmp = max(tmp, now);
        }
    }
    cout << res+tmp << endl;
    return 0;
}
