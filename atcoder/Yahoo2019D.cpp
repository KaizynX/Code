#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int n;
int a[Maxn], b[Maxn];

int main()
{
    cin >> n;
    int minv = 1e9;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(a[i] == 0)
        {
            b[i] = 1;
            continue;
        }
        if(a[i-1] == 0) a[i] = (a[i]%2 ? 1 : 2);
        else
        {
            if((a[i]-a[i-1])%2 == 0) a[i] = a[i-1];
            else a[i] = a[i-1]+(a[i]-a[i-1] < 0 ? -1 : 1);
        }
        minv = min(minv, a[i]);
    }
    if(minv%2) minv--;
    for(int i = 1; i <= n; ++i)
        if(!b[i]) a[i] -= minv;
    system("pause");
    return 0;
}