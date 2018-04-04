#include<iostream>
#include<math.h>
using namespace std;
void yi(int n,char a,char b,char c)
{
    int j=n;
    if(n==1)
    {
        cout<<n<<" from "<<a<<" to "<<c<<endl;
    }
    else
    {
        yi(n-1,a,c,b);
        cout<<j<<" from "<<a<<" to "<<c<<endl;
        yi(n-1,b,a,c);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    yi(n,'A','B','C');
    return 0;
}
