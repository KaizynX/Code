#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100;

int n;

int main()
{
    while(cin >> n)
    {
        string str;
        map<string, int> mmp;
        for(int i = 1; i <= n; ++i)
        {
            cin >> str;
            ++mmp[str];
        }
        cout << mmp.size() << endl;
    }
    return 0;
}
