#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int n;
int a[Maxn];

int main()
{
    cin >> n;
    int flag = 1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(a[i] == n) flag = i;
    }
    for(int i = 2; i < flag; ++i)
    {
        if(a[i] < a[i-1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i = flag+2; i <= n; ++i)
    {
        if(a[i] > a[i-1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
