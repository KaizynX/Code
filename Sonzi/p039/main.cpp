#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    if(x>=-2 && x<=2){
        if(y>=-2 && y<=2)
            cout<<"Ture";
        else cout <<"False";
    }
    else cout <<"False";
}
