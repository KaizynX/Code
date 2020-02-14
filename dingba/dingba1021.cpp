#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int n;
vector<int> v;

int main()
{
    v.emplace_back(0);
    for (int i = 1; v.size() < 1000; ++i) {
        int j = i;
        while (j%2 == 0) j /= 2;
        while (j%3 == 0) j /= 3;
        while (j%5 == 0) j /= 5;
        if (j == 1) v.emplace_back(i);
    }
    while (cin >> n && n) {
        cout << v[n] << endl;
    }
    return 0;
}
