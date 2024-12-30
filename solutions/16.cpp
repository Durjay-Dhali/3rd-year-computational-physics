#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double theta, double omega, double t){
    return (-9.8)*theta;
}
double g(double theta, double omega, double t){
    return omega;
}

void euler(double t0, double theta, double omega, double h){
    ofstream fout ("euler.dat");
    double omegaold;
    for(double t=t0;t<20;t+=h){
        fout<<t<<" "<<theta<<" "<<omega<<endl;
        omegaold = omega;
        omega += f(theta,omega,t)*h;
        theta += g(theta,omegaold,t)*h;
    }
}
void eulerCromer(double t0, double theta, double omega, double h){
    ofstream fout ("eulerC.dat");
    for(double t=t0;t<20;t+=h){
        fout<<t<<" "<<theta<<" "<<omega<<endl;
        omega += f(theta,omega,t)*h;
        theta += g(theta,omega,t)*h;
    }
}

int main(){
    euler(0,0,1,0.01);
    eulerCromer(0,0,1,0.01);
    return 0;
}