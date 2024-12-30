#include<iostream>
using namespace std;
double f(double x){
    return x*x*x+x-1;
}
void secant(double x1, double x2){
    if(f(x1)*f(x2)==0){
        cout<<"wrong guess"<<endl;
    }
    else{
        double x0;
        while(abs(x1-x2)>0.000001){
            x0=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
            x1=x2;
            x2=x0;
        }
        cout<<x0<<endl;
    }
}

int main(){
    secant(69,420);
    return 0;
}