#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a, b;

int main()
{
    cin >> a >> b;
    cout << max(0, a-b*2) << endl;
    return 0;
}
