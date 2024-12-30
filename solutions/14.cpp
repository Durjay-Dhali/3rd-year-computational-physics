#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
double f(double x){
    return sin(x);
}
double mc(double a, double b, int n){
    double c=0,d=1;
    double x,y,n0=0;
    srand(time(0));
    for(int i=0;i<n;i++){
        x= a+(b-a)*(double)rand()/RAND_MAX;
        y= c+(d-a)*(double)rand()/RAND_MAX;
        if(y<=f(x)){
            n0++;
        }
    }
    return (n0/n)*(b-a)*(d-c);
}
int main(){
    ofstream fout("data.dat");
    for(double n=10;n<=1000;n+=10){
        fout<<n<<" "<<abs(1-mc(0,M_PI/2.0,n))<<endl;
    }
    return 0;
}