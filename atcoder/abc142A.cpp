#include <bits/stdc++.h>

using namespace std;

int n, h, res;

int main()
{
    cin >> n >> h;
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        if (tmp >= h) ++res;
    }
    cout << res << endl;
    return 0;
}
