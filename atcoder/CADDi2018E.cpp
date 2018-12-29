#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 2e5+7;

int n;
int a[Maxn], op[Maxn];
long long ans;
long long l[Maxn], r[Maxn];

int main()
{
    cin >> n >> a[1];
    for(int i = 2; i <= n; ++i)
    {
        cin >> a[i];
        op[i] = (int)ceil(abs(log2((double)a[i-1]/a[i])));
    }
    // if a[<=i] be negative
    //    a[>i]  be positive
    l[0] = 0; l[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        // ��a[i]��ɸ���
        l[i] = l[i-1]+1;
        // ����[1, i-1]
        // a[i-1]*2^(op[i]+1) >= a[i]*2 op[i] ��Ϊż��
        if(a[i-1] < a[i])
            l[i] += 1ll*(i-1)*((op[i]+1)+(op[i]+1)%2);
    }
    r[n-1] = 0; r[n] = 0;
    for(int i = n-2; i >= 0; --i)
    {
        // ����i+1
        r[i] = r[i+1];
        // ����[i+2, n]
        // a[i+1] <= a[i+2]*2^(op[i+2])
        if(a[i+1] > a[i+2])
            r[i] += 1ll*(n-i-1)*(op[i+2]+op[i+2]%2);
    }
    ans = l[0]+r[0];
    for(int i = 0; i <= n; ++i)
    {
#ifdef DEBUG
        cout << i << " " <<  l[i] << " " << r[i] << endl;
#endif
        ans = min(ans, l[i]+r[i]);
    }
    cout << ans << endl;
    return 0;
}
