#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int testcase = 1;
int n;
int a[N];
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> s;
        int num = n, last = 0;
        for (int i = 0; i < n; ++i) {
            if (i == n-1 || s[i] == '>') {
                for (int j = i; j >= last; --j)
                    a[j] = num--;
                last = i+1;
            }
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i==n-1];
        
        num = 1; last = 0;
        for (int i = 0; i < n; ++i) {
            if (i == n-1 || s[i] == '<') {
                for (int j = i; j >= last; --j)
                    a[j] = num++;
                last = i+1;
            }
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}

