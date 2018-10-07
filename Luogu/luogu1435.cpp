#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e3+7;
const int INF = 0x3f3f3f3f;

string str;
int f[Maxn][Maxn], ans = INF, len;

int main()
{
    cin >> str;
    len = str.length();
    memset(f, 0x3f, sizeof f);
    f[0][len] = 1; f[1][len+1] = 1;
    if(str[0] == str[len-1]) f[1][len] = 0;
    for(int i = 1; i <= len; ++i)
    {
        for(int j = len; j >= i; --j)
        {
            f[i][j] = min(f[i][j], f[i][j+1]+1); // insert str[j] after i
            f[i][j] = min(f[i][j], f[i-1][j]+1); // insert str[i] before j
            if(str[i-1] == str[j-1]) f[i][j] = min(f[i][j], f[i-1][j+1]);
            // [1, i] <==> [j, len]
            if(j-i <= 1) ans = min(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
