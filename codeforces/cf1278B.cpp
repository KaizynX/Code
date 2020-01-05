#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
int a, b;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        if (a < b) swap(a, b);
        a -= b;
        int c = 0, t = 0;
        while (c < a) c += ++t; 
        if (c == a || (c-a)%2 == 0) {
            cout << t << endl;
            continue;
        }
        while (true) {
            c += ++t;
            if ((c-a)%2 == 0) {
                cout << t << endl;
                break;
            }
        }
    }
    return 0;
}

