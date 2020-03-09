#include <bits/stdc++.h>

using namespace std;

int x, y;

int main()
{
    while (cin >> x >> y) {
        cout << y/x << endl;
        int res = y/x;
        if (res < 0 || res > 10) cout << "fuck" << endl;
    }
    return 0;
}
