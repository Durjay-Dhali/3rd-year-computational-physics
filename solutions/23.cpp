#include<iostream>
#include<iomanip>
using namespace std;
double f1(double x){
    return (cos(x)*log(sin(x)))/(1+sin(x));
}
double f2(double x){
    return tan(x);
}
double simp(double a, double b, double(f)(double x)){
    int n=100;
    double d, I=0, J=0, A;
    d = (b-a)/n;
    for(int i=1;i<n;i+=2){
        I+=f(a+i*d);
    }
    for(int i=2;i<n;i+=2){
        J+=f(a+i*d);
    }
    A = (f(a)+4*I+2*J+f(b))*(d/3);
    return A;
}
int main(){
    double a=M_PI/4, b=M_PI/2;
    double c=0, d=3*M_PI/2;
    cout<<fixed<<setprecision(7)<<simp(a,b,f1)<<endl;
    cout<<fixed<<setprecision(7)<<simp(c,d,f2)<<endl;
    return 0;
}
