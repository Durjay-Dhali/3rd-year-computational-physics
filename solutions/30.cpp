#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double gamma (double n){
    if(n==0.5){
        return sqrt(M_PI);
    }
    if(n==1){
        return 1;
    }
    return (n-1)*gamma(n-1);
}
double fj(double theta, double z, double n){
    double a=(pow((z/2.0),n))/(sqrt(M_PI)*gamma(n+.5));
    double b=cos(z*sin(theta))*pow(cos(theta),2*n);
    return a*b;
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

double fs(double q, double x){
    return bessel(0,x);
}
double inte(double k, double q){
    double a=0,b=2*k*q, m=100;
    double h=(b-a)/m;
    double I=0,J=0;
    for(int i=1;i<m;i+=2){
        I+=fs(q,a+i*h);
    }
    for(int i=2;i<m;i+=2){
        J+=fs(q,a+i*h);
    }
    return (h/3.0)*(fs(q,a)+4*I+2*J+fs(q,b));
}
double transmitted(double k, double q){
    return 1-(1.0/(2*k*q))*inte(k, q);
}

int main(){
    double k = 2*M_PI;
    ofstream fout("data.dat");
    ofstream fout2("data2.dat");
    for(double z=0;z<=20;z+=0.01){
        fout<<z<<" "<<bessel(0,z)<<" "<<bessel(1,z)<<" "<<bessel(2,z)<<" "<<bessel(3,z)<<endl;
    }
    for(double q=0;q<=4;q+=0.01){
        fout2<<q<<" "<<transmitted(k,q)<<endl;
    }
    return 0;
}