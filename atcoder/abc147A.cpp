#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a[3];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int sum = 0;
    for (int i = 0; i < 3; ++i) cin >> a[i], sum += a[i];
    cout << (sum >= 22 ? "bust" : "win") << endl;
    return 0;
}
