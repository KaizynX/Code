#include <iostream>

using namespace std;

int m, f[2];

int main()
{
    cin >> m;
    f[0] = 0; f[1] = 1;
    for(int i = 2; i <= m*m; ++i)
    {
        f[i&1] = (f[0]+f[1])%m;
        if(f[i&1] == 1 && f[(i+1)&1] == 0)
        {
            cout << i-1 << endl;
            break;
        }
    }
    return 0;
}
