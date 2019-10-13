#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
string str;
int cnt[128], cnt0, cnt1;

int main()
{
    cin >> n >> str;
    for (int i = 0; i < n; ++i) {
        ++cnt[str[i]];
    }
    cnt1 = cnt['n'];
    cnt0 = cnt['z'];
    for (int i = 0; i < cnt1; ++i) {
        cout << 1 << " ";
    }
    for (int i = 0; i < cnt0; ++i) {
        cout << 0 << " ";
    }
    cout << endl;
    return 0;
}
