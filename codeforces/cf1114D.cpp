#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;

int n;
int c[Maxn], f[Maxn][Maxn];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    for(int i = 1; i <= 5000; ++i)
        f[1][i] = 1;
    f[1][c[1]] = 0;
    for(int i = 1; i < n; ++i)
    {
        // the min cost to print [1, i] to same
        int minv = f[i][1];
        for(int j = 2; j <= 5000; ++j)
            minv = min(minv, f[i][j]);

        cout << minv << endl;///
        // print i+1 to front || print [1, i] to c[i+1]
        f[i+1][c[i+1]] = min(minv+1, f[i][c[i+1]]);
        for(int j = 1; j <= 5000; ++j)
            if(j != c[i+1]) f[i+1][j] = min(minv+2, f[i][j]+1);
    }
    int ans = f[n][1];
    for(int i = 2; i <= 5000; ++i) ans = min(ans, f[n][i]);
    cout << ans << endl;
    system("pause");
    return 0;
}