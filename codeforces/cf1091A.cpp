#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main()
{
    cin >> a >> b >> c;
    cout << min(a, min(b-1, c-2))*3+3 << endl;
    return 0;
}
