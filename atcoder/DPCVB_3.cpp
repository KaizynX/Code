#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int Maxm = 50;

int n, k, tot;
int a[Maxn];
// cnt[i][j] 第i位为1的数第j位为0的个数
long long b[Maxn*Maxn], ans;
bitset<Maxn*Maxn> cnt[Maxm];

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
        for(int j = 0; (1ll<<j) <= b[i]; ++j)
            if(b[i]&(1ll<<j)) cnt[j].set(i);
    }

    int cur = Maxm, flag = 1;
    while(cur && flag)
    {
        flag = 0;
        for(int i = cur-1; i >= 0; --i)
            if(cnt[i].count() >= k)
            {
                flag = true;
                cur = i;
                ans += 1ll<<cur;
                // 选择了cur位,剩下的数的cur位必须为1
                for(int j = 0; j < cur; ++j) cnt[j] &= cnt[cur];
                break;
            }
    }
    cout << ans << endl;
    return 0;
}
