#include <iostream>

using namespace std;

int main()
{
    char a;cin>>a;
    if(a!='A' && a!='B' && a!='C' && a!='D' && a!='E' && a!='F' && a!='G' && a!='H' && a!='I' && a!='J' && a!='K' && a!='L' && a!='M' && a!='N' && a!='O' && a!='P' && a!='Q' && a!='R' && a!='S' && a!='T' && a!='U' && a!='V' && a!='W' && a!='X' && a!='Y' && a!='Z')
        cout<<"I do not like lowercase letters!";
    else{
        int n;cin>>n;
        char b[10000];
        int sum=0;
        for(int i=1;i<=n;++i){
            cin>>b[i];
            if(b[i]==a)sum++;
        }
        cout<<sum;
    }
    return 0;
}
