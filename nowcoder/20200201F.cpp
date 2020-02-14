#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;

int n, a, b, c, p, d;
int e[N][N], cnt[2];

int main()
{
    cin >> n >> a >> b >> c >> p >> d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            e[i][j] = e[j][i] =
                (1ll*a*(i+j)*(i+j)+1ll*b*(i-j)*(i-j)+c)%p>d;
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        cnt[0] = -1; cnt[1] = 0;
        for (int j = 1; j <= n; ++j)
            ++cnt[e[i][j]];
        res += 1ll*cnt[0]*cnt[1];
    }
    cout << n*(n-1ll)*(n-2)/6-res/2 << endl;
    return 0;
}
