#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    for (int i = 1; i <= (n+1)/2; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << c;
        cout << endl;
    }
    return 0;
}
