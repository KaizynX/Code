#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, a, b;
string name;

int main()
{
    cin >> n;
    while (n--) {
        cin >> name >> a >> b;
        if (a < 15 || a > 20 || b < 50 || b > 70) {
            cout << name << endl;
        }
    }
    return 0;
}
