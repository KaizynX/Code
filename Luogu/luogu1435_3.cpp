#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e3+7;
const int INF = 0x3f3f3f3f;

char str[Maxn];
int f[Maxn][Maxn], ans = INF, len;

int main()
{
    scanf("%s", str);
    len = strlen(str);
    for(int i = 1; i <= len; ++i)
        f[0][i] = f[i][0] = i;
    for(int i = 1; i <= len; ++i)
    {
        for(int j = 1; i+j <= len; ++j)
        {
            if(str[i-1] == str[len-j]) f[i][j] = f[i-1][j-1];
            else f[i][j] = min(f[i-1][j], f[i][j-1])+1;
            if(i+j >= len-1) ans = min(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
