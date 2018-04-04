#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string a;cin>>a;
    int b[27]={0};
    for(int i=0;i<=a.length();++i){
        switch (a[i]){
            case 'a':
                b[1]++;
                break;
            case 'b':
                b[2]++;
                break;
            case 'c':
                b[3]++;
                break;
            case 'd':
                b[4]++;
                break;
            case 'e':
                b[5]++;
                break;
            case 'f':
                b[6]++;
                break;
            case 'g':
                b[7]++;
                break;
            case 'h':
                b[8]++;
                break;
            case 'i':
                b[9]++;
                break;
            case 'j':
                b[10]++;
                break;
            case 'k':
                b[11]++;
                break;
            case 'l':
                b[12]++;
                break;
            case 'm':
                b[13]++;
                break;
            case 'n':
                b[14]++;
                break;
            case 'o':
                b[15]++;
                break;
            case 'p':
                b[16]++;
                break;
            case 'q':
                b[17]++;
                break;
            case 'r':
                b[18]++;
                break;
            case 's':
                b[19]++;
                break;
            case 't':
                b[20]++;
                break;
            case 'u':
                b[21]++;
                break;
            case 'v':
                b[22]++;
                break;
            case 'w':
                b[23]++;
                break;
            case 'x':
                b[24]++;
                break;
            case 'y':
                b[25]++;
                break;
            case 'z':
                b[26]++;
                break;
        }
    }
    int big=0;
    int small=100;
    for(int i=1;i<=26;++i){
        big=max(big,b[i]);
        if(b[i]!=0)small=min(small,b[i]);
    }
    int c=big-small;
    bool flag=true;
    if(c==1||c==0)cout<<"No Answer"<<endl<<0;
    else{
        for(int i=2;i<c;++i){
            if(c%i==0)flag=false;
        }
        if(flag==true)cout<<"Lucky Word"<<endl<<c;
        else cout<<"No Answer"<<endl<<0;
    }
    return 0;
}
