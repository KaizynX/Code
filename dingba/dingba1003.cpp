#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
char s;
string name[N];
int a[N];

int main()
{
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> name[i] >> a[i];
        }
        cin >> s;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (name[i][0] == s) {
                flag = 1;
                cout << name[i] << " " << a[i] << endl;
            }
        }
        if (!flag) cout << "NO" << endl;
    }
    return 0;
}
