#include<iostream>
using namespace std;
int main(){
    int a=7,b=0,m=91,x0=10;
    for(int i=0;i<100;i++){
        cout<<x0<<endl;
        x0=(a*x0+b)%m+10;
    }
    return 0;
}
