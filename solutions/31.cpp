#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double fact(double n){
    double result =1;
    for(int i=n;i>1;i--){
        result *=i;
    }
    return result;
}
double fj(double theta, double z, double n){
    double a = pow(z,n)/(pow(2,n+1)*fact(n));
    double b = pow(sin(theta),2*n+1);
    return a*cos(z*cos(theta))*b;
}
double bessel(int n, double z){
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
double gs(double u, double r){
    return (1-r*r)*bessel(0,u*r)*r;
}
double ant_radiation(double u){
    double a=0,b=1, m=100;
    double h=(b-a)/m;
    double I=0,J=0;
    for(int i=1;i<m;i+=2){
        I+=gs(u,a+i*h);
    }
    for(int i=2;i<m;i+=2){
        J+=gs(u,a+i*h);
    }
    return (h/3.0)*(gs(u,a)+4*I+2*J+gs(u,b));
}
int main(){
    ofstream fout("data.dat");
    ofstream fout2("data2.dat");
    for(double z=0;z<=25;z+=0.01){
        fout<<z<<" "<<bessel(0,z)<<" "<<bessel(1,z)<<" "<<bessel(2,z)<<" "<<bessel(3,z)<<endl;
    }
    for(double u=0;u<=25;u+=0.01){
        fout2<<u<<" "<<ant_radiation(u)<<endl;
    }
    return 0;
}