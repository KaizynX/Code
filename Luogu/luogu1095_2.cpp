#include <iostream>

using namespace std;

const int Maxt = 3e5+7;

int m, s, t;
int f[Maxt];

int main()
{
    cin >> m >> s >> t;
    for(int i = 1; i <= t; ++i)
    {
        if(m >= 10)
        {
            f[i] = f[i-1]+60;
            m -= 10;
        }
        else
        {
            f[i] = f[i-1];
            m += 4;
        }
    }
    for(int i = 1; i <= t; ++i)
        f[i] = max(f[i], f[i-1]+17);
    for(int i = 1; i <= t; ++i)
    {
        if(f[i] >= s)
        {
            cout << "Yes" << endl
                 << i << endl;
            return 0;
        }
    }
    cout << "No" << endl
         << f[t] << endl;
    return 0;
}
