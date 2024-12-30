#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("data.dat");
double f(double J, double T, double m){
    return tanh(J*m/T);
}
double find_m(double J, double T){
    double m=0.1;
    double m_new = f(J,T,m);
    while(abs(m_new-m)>0.00001){
        m=m_new;
        m_new=f(J,T,m);
    }
    return m;
}

int main(){
    double J=10;
    for(double T=10;T<=100;T=T+1){
        fout<<T<<" "<<find_m(J,T)<<endl;
    }

    
}