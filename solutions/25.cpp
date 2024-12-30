#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("data.dat");
double fact(double n){
    double result =1;
    for(int i=n;i>1;i--){
        result *=i;
    }
    return result;
}
double fj(double theta, double z, double n){
    double b = pow(sin(theta),2*n+1);
    return cos(z*cos(theta))*b;
}
double intgral(int n, double z){
    double a=0, b=M_PI, m=100;
    double h=(b-a)/m;
    double I=0,J=0;
    for(int i=1;i<m;i+=2){
        I+=fj(a+i*h,z,n);
    }
    for(int i=2;i<m;i+=2){
        J+=fj(a+i*h,z,n);
    }
    return (h/3.0)*(fj(a,z,n)+4*I+2*J+fj(b,z,n));
}
double bessel(int n, double z){
    double a = pow(z,n)/(pow(2,n+1)*fact(n));
    return a*intgral(n,z);
}
int main(){
    for(double z=0;z<=16;z+=0.01){
        fout<<z<<" "<<bessel(0,z)<<" "<<bessel(1,z)<<" "<<bessel(2,z)<<" "<<bessel(3,z)<<endl;
    }
    return 0;
}