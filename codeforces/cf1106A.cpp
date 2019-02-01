#include <bits/stdc++.h>

using namespace std;

const int Maxn = 507;

int n;
char a[Maxn][Maxn];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    int ans = 0;
    for(int i = 2; i < n; ++i)
        for(int j = 2; j < n; ++j)
            if(a[i][j] == 'X' && a[i-1][j-1] == 'X' && a[i-1][j+1] == 'X'
            && a[i+1][j-1] == 'X' && a[i+1][j+1] == 'X')
                ++ans;
    cout << ans << endl;
    return 0;
}
