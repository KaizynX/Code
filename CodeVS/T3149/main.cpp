#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;cin>>n;
    string a;
    for(int i=0;i<n;++i){
        cin>>a;
        int len=a.length();
        int flag=true;
        for(int j=0;j<len;j++){
            if(a[j]=='A'||a[j]=='a'
               ||a[j]=='B'||a[j]=='b'
               ||a[j]=='C'||a[j]=='c'
               ||a[j]=='D'||a[j]=='d'
               ||a[j]=='E'||a[j]=='e'
               ||a[j]=='F'||a[j]=='f'
               ||a[j]=='G'||a[j]=='g'
               ||a[j]=='H'||a[j]=='h'
               ||a[j]=='I'||a[j]=='i'
               ||a[j]=='J'||a[j]=='j'
               ||a[j]=='K'||a[j]=='k'
               ||a[j]=='L'||a[j]=='l'
               ||a[j]=='M'||a[j]=='m'
               ||a[j]=='N'||a[j]=='n'
               ||a[j]=='O'||a[j]=='o'
               ||a[j]=='P'||a[j]=='p'
               ||a[j]=='Q'||a[j]=='q'
               ||a[j]=='R'||a[j]=='r'
               ||a[j]=='S'||a[j]=='s'
               ||a[j]=='T'||a[j]=='t'
               ||a[j]=='U'||a[j]=='u'
               ||a[j]=='V'||a[j]=='v'
               ||a[j]=='W'||a[j]=='w'
               ||a[j]=='X'||a[j]=='x'
               ||a[j]=='Y'||a[j]=='y'
               ||a[j]=='Z'||a[j]=='z'
               )continue;
            else {
                flag=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl;
    }
    return 0;
}
