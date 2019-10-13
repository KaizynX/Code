#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 3e5+7;

int n;
int a[N];
vector<int> v;
string s;

int main()
{
    cin >> n >> s;
    for (int i = 0, j; i < s.length(); ++i) {
        j = i;
        while (j+1 < s.length() && s[j+1] == s[i]) ++j;
        v.push_back(j-i+1);
        i = j;
    }
    long long res = 1ll*n*(n-1)/2;
    for (int i = 0; i < v.size(); ++i) {
        if (i) res -= v[i-1]-1;
        if (i+1 < v.size()) res -= v[i+1];
    }
    cout << res << endl;
    return 0;
}
