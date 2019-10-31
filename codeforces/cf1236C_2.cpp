#include <bits/stdc++.h>

using namespace std;

const int N = 3e2+7;

int n;
int a[N][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        /*
        for (int j = 0; j < n; ++j) {
            cout << (j&1 ? i : n-i-1)+j*n+1 << " ";
        }
        */
        for (int j = 0; j < n; ++j) {
            if (i&1) {
                a[j][i] = i*n+j+1;
            } else {
                a[j][i] = i*n+n-j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
