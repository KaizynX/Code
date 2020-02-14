#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int num[] = {6,2,5,5,4,5,6,3,7,6};

int T, n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 3) {
            cout << 7 << endl;
        } else {
            for (int i = 1; i*2 <= n; ++i) {
                cout << 1;
            }
            cout << endl;
        }
    }
    return 0;
}
