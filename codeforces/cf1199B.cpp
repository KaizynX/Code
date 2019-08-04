#include <bits/stdc++.h>

using namespace std;

int H, L;

int main()
{
    cin >> H >> L;
    // (A+H)^2 = L^2+A^2
    // A2+2AH+H2 
    // A = (L^2-H^2)/2H

    // long double res = ((long double)L*L-(long double)H*H)/H/2;
    double res = ((double)L*L-(double)H*H)/H/2;
    printf("%.7f\n", res);
    return 0;
}
