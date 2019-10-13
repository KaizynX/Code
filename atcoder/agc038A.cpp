#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int h, w, a, b;
int r[N], c[N];

int main()
{
    cin >> h >> w >> a >> b;
    /*
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (r[i] < a && c[j] < b) {
                cout << 0 << " ";
                ++r[i];
                ++c[j];
            } else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
    */
    for (int i = 1; i <= b; ++i) {
        for (int j = 1; j <= a; ++j) {
            cout << 0;
        }
        for (int j = a+1; j <= w; ++j) {
            cout << 1;
        }
        cout << endl;
    }
    for (int i = b+1; i <= h; ++i) {
        for (int j = 1; j <= a; ++j) {
            cout << 1;
        }
        for (int j = a+1; j <= w; ++j) {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}
