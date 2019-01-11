#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int MOD = 1e9+7;

int H, W;
int m[Maxn][Maxn];

int main()
{
    char c;
    cin >> H >> W;
    for(int i = 1; i <= H; ++i)
        for(int j = 1; j <= W; ++j)
        {
            cin >> c;
            if(c == '.') m[i][j] = (m[i-1][j]+m[i][j-1])%MOD;
            if(i == 1 && j == 1) m[i][j] = 1;
        }
    cout << m[H][W] << endl;
    return 0;
}
