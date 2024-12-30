#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
    return sin(x);
}

double trap(double a, double b, int n){
    double d, I=0;
    d=(b-a)/n;
    for(int i=1;i<n;i++){
        I+=f(a+d*i);
    }
    return 0.5*d*(f(a)+2*I+f(b));
}

double simp(double a, double b, int n){
    double d, I=0, J=0;
    d=(b-a)/n;
    for(int i=1;i<n;i+=2){
        I+=f(a+i*d);
    }
    for(int j=2;j<n;j+=2){
        J+=f(a+j*d);
    }
    return (d/3.0)*(f(a)+4*I+2*J+f(b));
}

double simp3(double a, double b, int n){
    double d, I=0, J=0, K=0;
    d=(b-a)/n;
    for(int i=1;i<n;i+=3){
        I+=f(a+i*d);
    }
    for(int j=2;j<n;j+=3){
        J+=f(a+j*d);
    }
    for(int k=3;k<n;k+=3){
        K+=f(a+k*d);
    }
    return (3*d/8)*(f(a)+3*I+3*J+2*K+f(b));
}

int main(){
    double a=0, b=M_PI;
    int n=5000;
    cout<<"trap: "<<trap(a,b,n)<<endl;
    cout<<"simp: "<<simp(a,b,n)<<endl;
    cout<<"simp 1/3: "<<simp3(a,b,n)<<endl;
    return 0;
}