#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;
int a[Maxn];

int main()
{
    int cur = 0, flag = 0;
    long long r = 0;

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a+n);
    for(int i = 0; i < n; ++i)
    {
        if(i && a[i] == a[i-1])
        {
            if(++flag > 1 || a[i] == 0 || (i-2 >= 0 && a[i-2]+1 == a[i]) )
            {
                cout << "cslnb" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(a[i] >= cur)
        {
            r += a[i]-cur;
            a[i] = cur;
            ++cur;
        }
        else if(a[i] < cur)
            cur = a[i];
    }
    cout << (r&1 ? "sjfnb" : "cslnb") << endl;
    return 0;
}
