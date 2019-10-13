#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
int a[N][N];

int main()
{
    cin >> n;
    memset(a, -1, sizeof a);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == -1) a[i][j] = 0;
            if (a[i+1][j+2] == -1) a[i+1][j+2] = a[i][j]^1;
            if (a[i+2][j+1] == -1) a[i+2][j+1] = a[i][j]^1;
            /*
            if (a[i][j] == -1) {
                a[i][j] = 0;
                a[i+1][j+2] = a[i+1][j+2] == -1 ? 1 : a[i+1][j+2];
                a[i+2][j+1] = a[i+2][j+1] == -1 ? 1 : a[i+2][j+1];
            }
            */
            cout << ("WB"[a[i][j]]);
        }
        cout << endl;
    }
    return 0;
}
