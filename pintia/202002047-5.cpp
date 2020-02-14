#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int x, y;

int main()
{
    cin >> x >> y;
    cout << 100*100/2-100*(100-x+y)/2 << endl;
    return 0;
}
