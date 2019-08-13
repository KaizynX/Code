#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int n;
string str;
int room[20], pre[20], nex[20];

int main()
{
    cin >> n >> str;
    for(int i = 0; i < n; ++i) {
        if (str[i] == 'L') {
            int p = 0;
            while(p < 10 && room[p]) ++p;
            room[p] = 1;
        } else if (str[i] == 'R') {
            int p = 9;
            while(p >= 0 && room[p]) --p;
            room[p] = 1;
        } else {
            int num = str[i]-'0';
            room[num] = 0;
        }
    }
    for(int i = 0; i <= 9; ++i)
        cout << room[i];
    cout << endl;
    return 0;
}
