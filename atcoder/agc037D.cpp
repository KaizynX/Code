#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int kN = 1e2+7;

int n, m;
int a[kN][kN], sum[kN][kN], sort_a[kN];

inline void print()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            int group = (a[i][j]-1)/m+1;
            ++sum[j][group];
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            int group = (a[i][j]-1)/m+1;
#ifdef DEBUG
            cout << i << " " << j << " " << group << " " << sum[j][group] << endl;
#endif
            if (sum[j][group] > 1) {
                for (int k = j+1; k <= m; ++k) {
                    int gp = (a[i][k]-1)/m+1;
                    if (sum[k][gp] > 1 && !sum[j][gp] && !sum[k][group]) {
                        ++sum[j][gp];
                        --sum[j][group];
                        ++sum[k][group];
                        --sum[k][gp];
                        swap(a[i][j], a[i][k]);
                        break;
                    }
                }
            }
        }
    }
    print();
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            sort_a[i] = a[i][j];
        }
        sort(sort_a+1, sort_a+n+1);
        for (int i = 1; i <= n; ++i) {
            a[i][j] = sort_a[i];
        }
    }
    print();
    return 0;
}
