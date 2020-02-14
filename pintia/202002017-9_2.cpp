#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 55;

int n, k;
vector<int> a[N];

inline double calc(int x, int y)
{
    int nc = 0, nt = 0;
    for (int i = 0, j = 0; i < (int)a[x].size() && j < (int)a[y].size(); ++i) {
        while (j < (int)a[y].size() && a[x][i] > a[y][j]) ++j;
        if (a[x][i] == a[y][j]) ++nc;
    }
    int i = 0, j = 0;
    while (i < (int)a[x].size() && j < (int)a[y].size()) {
        if (a[x][i] == a[y][j]) {
            ++nt;
            ++i;
            ++j;
        } else if (a[x][i] < a[y][j]) {
            ++nt;
            ++i;
        } else if (a[x][i] > a[y][j]) {
            ++nt;
            ++j;
        }
    }
    nt += a[x].size()-i+a[y].size()-j;
#ifdef DEBUG
    cout << nc << " " << nt << endl;
#endif
    return 100.0*nc/nt;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0, m; i < n; ++i) {
        scanf("%d", &m);
        a[i].resize(m);
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
    }
    scanf("%d", &k);
    for (int i = 0, x, y; i < k; ++i) {
        scanf("%d %d", &x, &y);
        printf("%.2f%%\n", calc(x-1, y-1));
    }
    return 0;
}
