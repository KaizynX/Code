#include <iostream>
#define DEBUG 

using namespace std;

const int Maxn = 60;
const int INF = 0x3f3f3f3f;

int n, c;
int p[Maxn], w[Maxn], s[Maxn];
int f[Maxn][Maxn][2];
// f[l][r][i] ==> finish light [l, r] stop at (i == 0 ? left : right)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> c;
    for(int i = 1; i <= n; ++i)
    {
        cin >> p[i] >> w[i];
        s[i] = s[i-1]+w[i];
        f[i][i][0] = f[i][i][1] = INF;
    }
    f[c][c][0] = f[c][c][1] = 0;
    for(int len = 2; len <= n; ++len)
    {
        for(int l = 1, r, fee; l <= n-len+1; ++l)
        {
            r = l+len-1;
            fee = s[n]-(s[r]-s[l-1]);
            f[l][r][0] = min(f[l+1][r][0]+(fee+w[l])*(p[l+1]-p[l]),
                             f[l+1][r][1]+(fee+w[l])*(p[r]-p[l])  );
            f[l][r][1] = min(f[l][r-1][0]+(fee+w[r])*(p[r]-p[l]),
                             f[l][r-1][1]+(fee+w[r])*(p[r]-p[r-1]));
#ifdef DEBUG
            cout << fee << " " << l << " " << r << " "
                 << f[l][r][0] << " " << f[l][r][1] << endl;
#endif
        }
    }
    cout << min(f[1][n][0], f[1][n][1]) << endl;
    return 0;
}
