#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

vector<int> v;

int main()
{
    int a;
    while (cin >> a) v.emplace_back(a);
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
        if (i) cout << "->";
        cout << v[i];
    }
    cout << endl;
    return 0;
}
