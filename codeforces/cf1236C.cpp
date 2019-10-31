#include <bits/stdc++.h>

using namespace std;

const int N = 3e2+7;

int n;
int a[N][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j][i] = i*n+(j+i)%n;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j]+1 << " ";
        }
        cout << endl;
    }
    return 0;
}
