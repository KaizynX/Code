#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> v;

int main()
{
    cin >> a >> b;
    v.emplace_back(a);
    v.emplace_back(b);
    for(auto i : v) cout << i << endl;
    system("pause");
    return 0;
}
