#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;

int main()
{
    int flag = 0;
    while (cin >> n) {
        if (flag) cout << endl;
        flag = 1;
        for (int i = 1; i <= n/2; ++i) {
            for (int j = 1; j <= n/2-i+1; ++j) cout << " ";
            for (int j = 1; j <= i; ++j) cout << "*";
            cout << endl;
        }
        for (int i = 1; i <= n; ++i) cout << "*";
        cout << endl;
        for (int i = n/2; i; --i) {
            for (int j = 1; j <= n/2; ++j) cout << " ";
            for (int j = 1; j <= i; ++j) cout << "*";
            cout << endl;
        }
    }
    return 0;
}
