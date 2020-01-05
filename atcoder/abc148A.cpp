#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a, b;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    for (int i = 1; i <= 3; ++i) {
        if (a != i && b != i) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
