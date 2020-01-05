#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;

int T, bx, ex, by, ey;
int sg[10][10];

int main()
{
    sg[0][0] = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < i; ++k)
                sg[i][j] |= sg[k][j]^1;
            for (int k = 0; k < j; ++k)
                sg[i][j] |= sg[i][k]^1;
#ifdef DEBUG
            printf("sg[%d][%d]=%d\n", i, j, sg[i][j]);
#endif
        }
    }
    sg[0][0] = 1;
    cin >> T;
    while (T--) {
        cin >> bx >> by >> ex >> ey;
        int dx = abs(bx-by), dy = abs(ex-ey);
        dx = min(dx, 9); dy = min(dy, 9);
        cout << (sg[dx][dy] ? "Seele" : "Bronya") << endl;
    }
    return 0;
}

