#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e4;
const int Maxm = 107;
const int INF = 0x3f3f3f3f;

int L, S, T, M;
int a[Maxm], d[Maxn];
int f[Maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> S >> T >> M;
    for(int i = 1; i <= M; ++i)
        cin >> a[i];
    sort(a+1, a+M+1);
    if(S == T)
    {
        int cnt = 0;
        for(int i = 1; i <= M; ++i)
            if(a[i] % S == 0) cnt++;
        cout << cnt << endl;
        return 0;
    }
    a[M+1] = L;
    int p = 0;
    for(int i = 1; i <= M+1; ++i)
    {
        p += min(a[i]-a[i-1], 72);
        d[p] = 1;
    }
    for(int i = 1; i < p; ++i)
    {
        f[i] = INF;
        for(int j = S; j <= T; ++j)
        {
            if(i < j) break;
            f[i] = min(f[i], f[i-j]+d[i]);
        }
    }
    f[p] = INF;
    for(int i = max(0, p-T); i < p; ++i)
        f[p] = min(f[p], f[i]);
    cout << f[p] << endl;
    return 0;
}
