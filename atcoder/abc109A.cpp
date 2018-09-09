#include <cstdio>
#include <iostream>

using namespace std;

int a, b;
// int r[5][5];

int main()
{
    cin >> a >> b;
    /*
    if(a > b) swap(a, b);
    r[1][1] = 1;
    r[1][2] = 0;
    r[1][3] = 1;
    r[2][2] = 0;
    r[2][3] = 0;
    r[3][3] = 1;
    if(r[a][b]) cout << "Yes" << endl;
    else cout << "No" << endl;
    */
    if(a == 2 || b == 2) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
