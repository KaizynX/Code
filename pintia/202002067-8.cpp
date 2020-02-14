#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
double h;
char sex;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> sex >> h;
        if (sex == 'F') printf("%.2f\n", 1.09*h);
        else printf("%.2f\n", h/1.09);
    }
    return 0;
}
