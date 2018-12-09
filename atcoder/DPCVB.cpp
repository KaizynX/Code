#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 1e3+7;
const int Maxm = 40;

int n, k;
int a[Maxn], cnt[Maxm][Maxm];
// cnt[i][j] 第i位为1的数第j位为1的个数
long long b[Maxn*Maxn], tot, ans;
bitset<Maxm> bi;

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        long long tmp = 0;
        for(int j = i; j; --j)
        {
            tmp += a[j];
            b[++tot] = tmp;
        }
    }
    sort(b+1, b+tot+1);
    reverse(b+1, b+tot+1);
    for(int i = 1; i <= tot; ++i)
    {
        bi = b[i];
        for(int j = 0; (1<<j) <= b[i]; ++j)
        {
            if(!bi[j]) continue;
            for(int jj = j; jj >= 0; --jj)
                if(bi[j]) cnt[j][jj]++;
        }
    }

    int cur = -1;
    for(int i = Maxm-1; i >= 0; --i)
        if(cnt[i][i] >= k)
        {
            cur = i;
            break;
        }
    if(cur == -1) return puts("0")&0;
    ans += 1ll<<cur;
    while(cur)
        for(int i = cur-1; i >= 0; --i)
            if(cnt[cur][i] >= k)
            {
                cur = i;
                ans += 1<<cur;
                break;
            }
    cout << ans << endl;
    return 0;
}
