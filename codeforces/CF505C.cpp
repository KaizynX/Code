#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int ans = 1;
string str;

int main()
{
    cin >> str;
    str += str;
    for(int i = 1, cnt = 1; i < str.length(); ++i)
    {
        if(str[i] != str[i-1])
        {
            ans = max(ans, ++cnt);
            if(ans == str.length()/2) break;
        }
        else cnt = 1;
    }
    cout << ans << endl;
    return 0;
}
