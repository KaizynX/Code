//为什么sort有毒
//sort什么的从0开始，嗯，就是这个意思
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int k = 0; k<n; k++){
        cout << a[k] << " ";
    }
    cout<<endl;
    return 0;
}
/*#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[10]={2,4,1,23,5,76,0,43,24,65},i;
    for(i=1;i<=10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    sort(a,a+10);
    for(i=1;i<=10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
*/
