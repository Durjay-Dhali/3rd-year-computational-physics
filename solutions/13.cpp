#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
double pi(int n){
    double n0=0;
    double x,y;
    srand(time(0));
    for(int i=0;i<n;i++){
        x=(double)rand()/RAND_MAX;
        y=(double)rand()/RAND_MAX;
        if(sqrt(x*x+y*y)<=1){
            n0++;
        }
    }
    return 4*n0/n;
}
int main(){
    for(int n=1;n<1000000;n*=10){
        cout<<"n="<<n<<": "<<pi(n)<<endl;
    }
    return 0;
}
