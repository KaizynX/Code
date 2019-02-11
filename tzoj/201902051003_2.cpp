#include <bits/stdc++.h>

using namespace std;

const int Maxn = 50;

int C, n, ans;
int a[Maxn];

void brute(int cur)
{
    if(cur > n)
    {
        ans++;
        return;
    }
    if(cur == 1 || cur == 2)
    {
        for(int i = 1; i <= 3; ++i)
        {
            a[cur] = i;
            brute(cur+1);
        }
    }
    else
    {
        for(int i = 1; i <= 3; ++i)
        {
            int t1 = a[cur-2], t2 = a[cur-1];
            if(t1 != t2 && i != t1 && i != t2) continue;
            a[cur] = i;
            brute(cur+1);
        }
    }
    
}

int main()
{
    cin >> C;
    while(C--)
    {
        ans = 0;
        cin >> n;
        brute(1);
        cout << ans << endl;
    }
    return 0;
}