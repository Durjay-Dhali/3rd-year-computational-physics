#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double fa(double nA, double tA, double t){
    return -nA/tA;
}
double fB(double nA, double nB, double t, double factor){
    return -fa(nA, factor, t)- nB;
}
void rk(double factor,double h, string filename){
    ofstream fout(filename);
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
    double factors[6] = {1/20.0, 1/10.0, 1/5.0, 1, 5, 10};
    double h = 0.01;
    for (int i=0; i<6; i++) {
        string filename = "data" + to_string(i+1) + ".dat";
        rk(factors[i], h, filename);
    }
}    
