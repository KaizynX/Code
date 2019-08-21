#include <bits/stdc++.h>

using namespace std;

int main()
{
    int res = 1;
    for (int i = 1; i <= 101; ++i)
        res = (res*2)%26;
    cout << res << endl;
    return 0;
}
