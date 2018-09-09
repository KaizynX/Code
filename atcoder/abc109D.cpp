#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 507;

int h, w;
int a[Maxn][Maxn];
int has[Maxn][Maxn];

int main()
{
    scanf("%d%d", &h, &w);
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            scanf("%d", &a[i][j]);
    for(int i = h; i; --i)
        for(int j = w; j; --j)
            has[i][j] = (a[i][j]&1) || has[i+1][j] || has[i][j+1];
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            if(a[i][j]&1)
            {
                // move right
                int judge = 0;
                for(int k = j+1; k <= w; ++k)
                    if(a[i][k]&1) { judge = 1; break; }
                if(judge)
                {
                    printf("%d %d %d %d\n", i, j, i, j+1);
                    a[i][j+1]++;
                    continue;
                }
                // move down
                if(i < h && has[i+1][j])
                {
                    printf("%d %d %d %d\n", i, j, i+1, j);
                    a[i+1][j]++;
                }
            }
    return 0;
}
