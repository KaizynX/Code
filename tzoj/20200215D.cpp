#include <bits/stdc++.h>

using namespace std;

int cnt[3][3];

void f(int n, int a, int b, int c)
{
    if (n == 1) { ++cnt[a][c]; return; }
    f(n-1, a, c, b);
    ++cnt[a][c];
    f(n-1, b, a, c);
}

int main()
{
    int n;
    while (cin >> n) {
        memset(cnt, 0, sizeof cnt);
        f(n, 0, 1, 2);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) continue;
                cout << (char)('A'+i) << "->" << (char)('A'+j) << ": " << cnt[i][j] << endl;
            }
        }
    }
    return 0;
}
