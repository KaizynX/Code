#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 1e3+7;
const int Maxm = 40;

int n, k;
int a[Maxn];
// cnt[i][j] ��iλΪ1������jλΪ0�ĸ���
long long b[Maxn*Maxn/2], tot, ans;
bitset<Maxm> bi;
bitset<Maxn*Maxn/2> cnt[Maxm];

#ifdef DEBUG
inline void print(const bitset<Maxn*Maxn/2> &bbb)
{
    for(int i = 1; i <= tot; ++i)
        putchar(bbb[i]+'0');
    putchar('\n');
}
#endif

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
#ifdef DEBUG
        cout << b[i] << ' ';
#endif
        bi = b[i];
        for(int j = 0; (1<<j) <= b[i]; ++j)
            if(bi[j]) cnt[j] |= 1<<i;
    }

#ifdef DEBUG
    cout << endl;
    for(int i = 0; i < 4; ++i)
        print(cnt[i]);
#endif

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
                // ѡ����curλ,ʣ�µ�����curλ����Ϊ1
                for(int j = 0; j < cur; ++j) cnt[j] &= cnt[cur];
                break;
            }
#ifdef DEBUG
    cout << endl;
    for(int i = 0; i < 4; ++i)
        print(cnt[i]);
#endif
    }
    cout << ans << endl;
    return 0;
}
