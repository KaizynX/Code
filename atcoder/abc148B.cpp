#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
string s, t;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        cout << s[i] << t[i];
    }
    cout << endl;
    return 0;
}

