#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int n;
string str;
int room[20], pre[20], nex[20];

inline void del(int x)
{
    pre[nex[x]] = pre[x];
    nex[pre[x]] = nex[x];
}

inline void add(int x)
{
    pre[x] = pre[11];
    nex[x] = 11;
    nex[pre[11]] = x;
    pre[11] = x;
}

int main()
{
    cin >> n >> str;
    for(int i = 1; i <= 10; ++i) {
        pre[i] = i-1;
        nex[i]= i+1;
    }
    nex[0] = 1; pre[11] = 10;
    for(int i = 0; i < n; ++i) {
        if (str[i] == 'L') {
            ;
        } else if (str[i] == 'R') {
            ;
        } else {
            int num = str[i]-'0'+1;
        }
    }
    for(int i = 1; i <= 10; ++i)
        cout << room[i] << (i == 10 ? '\n' : ' ');
    return 0;
}
