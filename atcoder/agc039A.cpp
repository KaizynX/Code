#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e2+7;

int k;
long long res;
string str;

int main()
{
    cin >> str >> k;
    int cnt = 1;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == str[i-1]) {
            ++cnt;
        } else {
            res += cnt/2;
            cnt = 1;
        }
    }
    res += cnt/2;
    if (k == 1 || str[0] != str[str.length()-1]) {
        cout << res*k << endl;
        return 0;
    }
    if (k > 1 && str[0] == str[str.length()-1]) {
        int i = 0, j = str.length()-1;
        while (i+1 < j && str[i+1] == str[0]) ++i;
        while (j-1 > i && str[j-1] == str[0]) --j;
#ifdef DEBUG
        cout << i << " " << j << endl;
#endif
        if (i+1 == j) {
            res = (long long)str.length()*k/2;
        } else {
            cnt = i-j+1+str.length();
            res -= (i+1)/2+(str.length()-j)/2;
            res = 1ll*(cnt/2)*(k-1)+1ll*res*k+(i+1)/2+(str.length()-j)/2;
        }
    }
    cout << res << endl;
    return 0;
}
