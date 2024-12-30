#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
    return -pow(x,6)+pow(x,5)+2*pow(x,4)-2*pow(x,3)+x*x+2*x-1;
}
void secant(double x1, double x2){
    if(f(x1)*f(x2)==0){
        cout<<"wrong guess"<<endl;
    }
    else{
        double x0,n=0;
        while(abs(x1-x2)>=1e-20){
            x0=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
            x1=x2;
            x2=x0;
            n++;
        }
        cout<<x0<<" "<<n<<endl;

    }
}

int main(){
    secant(-100,100);
    return 0;
}