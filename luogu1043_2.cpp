#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 52;
const int Maxm = 10;

int n, m, ans_min, ans_max;
int a[Maxn<<1], s[Maxn<<1];
int f_max[Maxn<<1][Maxn<<1][Maxm];
int f_min[Maxn<<1][Maxn<<1][Maxm];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
        cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	for(int i = n+1; i <= 2*n; ++i)
	{
		a[i] = a[i-n];
		s[i] = s[i-1] + a[i];
	}
    memset(f_min, 0x7f, sizeof f_min);
    for(int i = 1; i <= 2*n; ++i)
        for(int j = i; j <= 2*n; ++j)
            f_max[i][j][1] = f_min[i][j][1] = ((s[j]-s[i-1])%10+10)%10;
    for(int k = 2; k <= m; ++k)
        for(int len = k; len <= n; ++len)
            for(int l = 1, r; l <= 2*n-len+1; ++l)
            {
                r = l+len-1;
                for(int d = l; d < r; ++d)
                {
                    if(r-d >= k-1)
                    {
                        f_max[l][r][k] = max(f_max[l][r][k], f_max[l][d][1]*f_max[d+1][r][k-1]);
                        f_min[l][r][k] = min(f_min[l][r][k], f_min[l][d][1]*f_min[d+1][r][k-1]);
                    }
                    if(d-l+1 >= k-1)
                    {
                        f_max[l][r][k] = max(f_max[l][r][k], f_max[l][d][k-1]*f_max[d+1][r][1]);
                        f_min[l][r][k] = min(f_min[l][r][k], f_min[l][d][k-1]*f_min[d+1][r][1]);
                    }
                }
            }

    ans_max = 0; ans_min = 0x3f3f3f3f;
    for(int i = 1; i <= n; ++i)
    {
        ans_max = max(ans_max, f_max[i][i+n-1][m]);
        ans_min = min(ans_min, f_min[i][i+n-1][m]);
    }
    cout << ans_min << endl << ans_max << endl;
	return 0;
}
