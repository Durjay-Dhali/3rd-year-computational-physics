#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout ("data6.dat");
double fa(double nA, double tA, double t){
    return -nA/tA;
}
double fB(double nA, double nB, double t, double factor){
    double tA=factor, tB=1.0;
    return nA/tA - nB/tB;
}
void rk(double factor,double h){
    double nA=1,nB=0;
    for(double t=0; t<20; t+=h){
        fout<<t<<" "<<nA<<endl;
        double k1 = h*fa(nA, factor, t);
        double k2 = h*fa(nA+(k1/2), factor, t+h/2);

        double l1 = h*fB(nA, nB, t, factor);
        double l2 = h*fB(nA, nB+l1/2, t+h/2, factor);
        
        nA+=k2;
        nB+=l2;
    }
}

int main(){
    rk(1/20.0,0.01);
}    