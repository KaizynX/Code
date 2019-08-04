#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int T, n, a;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        int maxfv = 0, maxsv = 0, res = 0;
        cin >> a;
        maxfv = a;
        cin >> a;
        maxsv = min(a, maxfv);
        maxfv = max(a, maxfv);
        for(int i = 3; i <= n; ++i)
        {
            cin >> a;
            if(a >= maxfv)
            {
                maxsv = maxfv;
                maxfv = a;
            }
            else if(a > maxsv)
                maxsv = a;
        }
        res = min(maxsv-1, n-2);
        cout << res << endl;
    }
    return 0;
}
