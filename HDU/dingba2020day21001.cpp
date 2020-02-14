#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n;
int a[N][N];

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= i; ++j) 
                cin >> a[i][j];
        for (int i = n-1; i; --i)
            for (int j = 1; j <= i; ++j)
                a[i][j] += max(a[i+1][j], a[i+1][j+1]);
        cout << a[1][1] << endl;
    }
    return 0;
}
