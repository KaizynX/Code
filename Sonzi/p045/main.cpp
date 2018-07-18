#include <iostream>

using namespace std;

int main()
{
    int n,sa,sb,sc;
    string a[n];
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]='a' || a[i]='A')sa++;
        if(a[i]='b' || a[i]='B')sb++;
        if(a[i]='c' || a[i]='C')sc++;
        }
    }
    if(sa>=sb && sb>=sc){
        cout<<"a "<<sa<<endl;
        cout<<"b "<<sb<<endl;
        cout<<"c "<<sc<<endl;
    }
    if(sa>=sc && sc>=sb){
        cout<<"a "<<sa<<endl;
        cout<<"c "<<sc<<endl;
        cout<<"b "<<sb<<endl;
    }
    if(sb>=sa && sa>=sc){
        cout<<"b "<<sb<<endl;
        cout<<"a "<<sa<<endl;
        cout<<"c "<<sc<<endl;
    }
    if(sb>=sc && sc>=sa){
        cout<<"b "<<sb<<endl;
        cout<<"c "<<sc<<endl;
        cout<<"a "<<sa<<endl;
    }
    if(sc>=sa && sa>=sb){
        cout<<"c "<<sc<<endl;
        cout<<"a "<<sa<<endl;
        cout<<"b "<<sb<<endl;
    }
    if(sc>=sb && sb>=sa){
        cout<<"c "<<sc<<endl;
        cout<<"b "<<sb<<endl;
        cout<<"a "<<sa<<endl;
    }
    return 0;
}
