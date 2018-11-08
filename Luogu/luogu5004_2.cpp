#include <bits/stdc++.h>

using namespace std;

const int Maxm = 20;
const int MOD = 1e9+7;

int n, m, ans;
int s[Maxm];

int main()
{
    scanf("%d%d", &n, &m);
    s[0] = 1;
    for(int i = 1, fi; i <= n; ++i)
    {
        fi = s[max(0, i-m-1)%m];
        s[i%m] = (s[(i-1)%m]+fi)%MOD;
    }
    printf("%d\n", s[n%m]);
    return 0;
}
