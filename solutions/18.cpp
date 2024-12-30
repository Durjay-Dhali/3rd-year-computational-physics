#include<iostream>
#include<fstream>
using namespace std;
ofstream fout ("data.dat");
const double k=150, m=7.2;
double f(double x){
    return (-k*x)/m;
}
void verlet(double t0, double x, double v, double h){
    for(double t=t0; t<10;t+=h){
        double xold = x;
        fout<<t<<" "<<x<<" "<<v<<endl;
        x+=h*(v+h/2.0*f(x));
        v+=(h/2.0)*(f(xold)+f(x));
    }
}
int main(){
    double t=0, x=1,v=0, h=0.01;
    verlet(t,x,v,h);
    return 0;
}
