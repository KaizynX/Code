#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
string str;
int a[10];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof a);
        cin >> str;
        int n = str.length();
        int sum = 0;
        for (char c : str) {
            ++a[c-'0'];
            sum += c-'0';
        }
        n -= a[0];
        if (!a[0] || sum%3) {
            cout << "cyan" << endl;
            continue;
        }
        if (n == 0 || a[0] > 1 || (n >= 2 && (a[2] || a[4] || a[6] || a[8]))) {
            cout << "red" << endl;
            continue;
        }
        int num = 0;
        for (int i = 1; i <= 9; ++i) {
            if (a[i]) num = i;
        }
        cout << (num == 6 ? "red" : "cyan") << endl;
    }
    return 0;
}
