#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

double R, r, h;

int main()
{
    while (cin >> R >> r >> h) {
        printf("%.2f\n", PI*(R*R-r*r)*h);
    }
    return 0;
}
