#include <bits/stdc++.h>

using namespace std;

int a, b;
int d[5];

int main()
{
    for(int i = 0; i < 3; ++i)
    {
        cin >> a >> b;
        d[a]++; d[b]++;
    }
    int cnt = 0;
    for(int i = 1; i <= 4; ++i)
    {
        cnt += d[i]&1;
    }
    cout << (cnt <= 2 ? "YES" : "NO") << endl;
    system("pause");
    return 0;
}