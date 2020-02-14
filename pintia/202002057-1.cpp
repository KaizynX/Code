#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, sum;
int a[N];
vector<int> res[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1, j = 0, cnt = 1; cnt <= sum*10; ++cnt, ++i, j = (j+1)%n) {
        while ((int)res[j].size() >= a[j]*10) j = (j+1)%n;
        if (res[j].empty() || res[j].back()+1 < i) res[j].emplace_back(i);
        else res[j].emplace_back(++i);
    }
    for (int i = 0; i < n; ++i) {
        cout << "#" << i+1 << endl;
        for (unsigned j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " \n"[j%10==9];
        }
    }
    return 0;
}
