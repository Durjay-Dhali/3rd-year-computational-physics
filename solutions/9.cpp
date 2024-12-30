#include<iostream>
#include<cmath>
#include<fstream>
#define N 300
using namespace std;

int main(){
    ofstream fout ("data.dat");
    double angle[N], f[N], df[N];
    double h = 2.0*M_PI/(N-1);
    for(int i=0;i<N;i++){
        angle[i]=i*h;
        f[i]=sin(angle[i]);
    }
    df[0]=(f[1]-f[0])/h;
    df[N-1]=(f[N-1]-f[N-2])/h;
    for(int i=1;i<N-1;i++){
        df[i]=(f[i+1]-f[i-1])/(2*h);
    }
    for(int i=0;i<300;i++){
        cout<<angle[i]<<" "<<f[i]<<" "<<df[i]<<" "<<abs(df[i]-cos(angle[i]))<<endl;
        fout<<angle[i]<<" "<<f[i]<<" "<<df[i]<<" "<<abs(df[i]-cos(angle[i]))<<endl;
    }

}
