#include <iostream>
#include <string>
using namespace std;
char a1[7],b1[7];
int a2[7],b2[7];
int main()
{
    string a,b;
    cin>>a>>b;
    long long sa=1,sb=1;
    int l=a.length();
    if(a.length()<b.length())l=b.length();
    for(int i=1;i<=a.length();i++){
        a1[i]=a[i-1];
        b1[i]=b[i-1];
        if(a1[i]=='A')a2[i]=1;
        else if(a1[i]=='B')a2[i]=2;
        else if(a1[i]=='C')a2[i]=3;
        else if(a1[i]=='D')a2[i]=4;
        else if(a1[i]=='E')a2[i]=5;
        else if(a1[i]=='F')a2[i]=6;
        else if(a1[i]=='G')a2[i]=7;
        else if(a1[i]=='H')a2[i]=8;
        else if(a1[i]=='I')a2[i]=9;
        else if(a1[i]=='J')a2[i]=10;
        else if(a1[i]=='K')a2[i]=11;
        else if(a1[i]=='L')a2[i]=12;
        else if(a1[i]=='M')a2[i]=13;
        else if(a1[i]=='N')a2[i]=14;
        else if(a1[i]=='O')a2[i]=15;
        else if(a1[i]=='P')a2[i]=16;
        else if(a1[i]=='Q')a2[i]=17;
        else if(a1[i]=='R')a2[i]=18;
        else if(a1[i]=='S')a2[i]=19;
        else if(a1[i]=='T')a2[i]=20;
        else if(a1[i]=='U')a2[i]=21;
        else if(a1[i]=='V')a2[i]=22;
        else if(a1[i]=='W')a2[i]=23;
        else if(a1[i]=='X')a2[i]=24;
        else if(a1[i]=='Y')a2[i]=25;
        else if(a1[i]=='Z')a2[i]=26;
        else a2[i]=1;
        sa*=a2[i];
        if(b1[i]=='A')b2[i]=1;
        else if(b1[i]=='B')b2[i]=2;
        else if(b1[i]=='C')b2[i]=3;
        else if(b1[i]=='D')b2[i]=4;
        else if(b1[i]=='E')b2[i]=5;
        else if(b1[i]=='F')b2[i]=6;
        else if(b1[i]=='G')b2[i]=7;
        else if(b1[i]=='H')b2[i]=8;
        else if(b1[i]=='I')b2[i]=9;
        else if(b1[i]=='J')b2[i]=10;
        else if(b1[i]=='K')b2[i]=11;
        else if(b1[i]=='L')b2[i]=12;
        else if(b1[i]=='M')b2[i]=13;
        else if(b1[i]=='N')b2[i]=14;
        else if(b1[i]=='O')b2[i]=15;
        else if(b1[i]=='P')b2[i]=16;
        else if(b1[i]=='Q')b2[i]=17;
        else if(b1[i]=='R')b2[i]=18;
        else if(b1[i]=='S')b2[i]=19;
        else if(b1[i]=='T')b2[i]=20;
        else if(b1[i]=='U')b2[i]=21;
        else if(b1[i]=='V')b2[i]=22;
        else if(b1[i]=='W')b2[i]=23;
        else if(b1[i]=='X')b2[i]=24;
        else if(b1[i]=='Y')b2[i]=25;
        else if(b1[i]=='Z')b2[i]=26;
        else b2[i]=1;
        sb*=b2[i];
    }
    if(sa%47==sb%47)cout<<"GO";
    else cout<<"STAY";
    return 0;
}
