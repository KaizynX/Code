#include <bits/stdc++.h>

using namespace std;

const int kN = 3e3+7;

int n, m, tail, ans;
int up[kN][kN];
// first : height, second : pos
pair<int, int> stac[kN];
char a[kN][kN];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", a[i]+1);
        // the number of 0 in up[i][1~j] 
        for(int j = 1; j <= m; ++j)
            if (a[i][j] == '1')
                up[i][j] = up[i-1][j]+1;
    }
    for(int i = 1, right0; i <= n; ++i) {
        // the right pos of 0 in a[i+1][:]
        right0 = -1;
        tail = 0;
        for(int j = 1, pos; j <= m+1; ++j) {
            // the left side of submatrices
            pos = j;
            while(tail && stac[tail].first > up[i][j]) {
                // (i-up[i][j]+1, stac[tail].second) -> (i, j)
                if (stac[tail].second <= right0)
                    ++ans;
                pos = stac[tail].second;
                --tail;
            }
            if (!up[i+1][j])
                right0 = j;
            if (up[i][j] && (!tail || stac[tail].first < up[i][j]))
                stac[++tail] = { up[i][j], pos };
        }
    }
    printf("%d\n", ans);
    return 0;
}
