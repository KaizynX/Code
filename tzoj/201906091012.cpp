#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;

int T, n;
int a[Maxn];

inline bool check(int cur, int sum)
{
    int tmp = 0, cnt = 0;
    for(int i = cur; i <= n; ++i)
    {
        tmp += a[i];
        if(tmp == sum) tmp = 0, cnt++;
        else if(tmp > sum) return false;
    }
    return !tmp && cnt;
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        char c;
        int flag = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin >> c;
            a[i] = c-'0';
        }
        for(int i = 1, tmp = 0; i < n; ++i)
        {
            tmp += a[i];
            if(check(i+1, tmp))
            {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
