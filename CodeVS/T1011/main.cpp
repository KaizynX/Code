#include <iostream>
//²»¶Ô°¡
using namespace std;
int s=1;
void f(int a){
    int k=1;
    for(int j=k;j<=a;j++){
        s++;
    }
    a=a/2;
    if(a!=1&&a!=0)return f(a);
}
int main()
{
    int n,h;
    cin>>n;
    h=n/2;
    for(int i=1;i<=h;++i){
        int i1=i;
        f(i1);
    }
    cout<<s<<endl;
    return 0;
}
/*#include<iostream>
using namespace std;
int main()
{
    int i, j, t;
    int sum = 1;
    int n;
    int a[100] = {0};
    cin >> n;
    t = n / 2;
    for(i=1; i <= t; i++)
    {
        for(j=1; j <= i/2; j++)
        {
            a[i] += a[j];
        }
        a[i]++;
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
*/
