#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
    return cos(x);
}
double rombTrap(double a, double b, int m, int n){
    double trp[5][5];
    double x, sum, h, factor;
    int i,j,k;
    h=(b-a)/n;

    for(k=0;k<=m;k++){
        sum = f(a);
        for(i=1;i<n;i++){
            sum += 2*f(a+i*h);
        }
        sum+=f(b);
        trp[0][k]=0.5*h*sum;

        h=h/2;
        n=n*2;
    }

    for(i=1;i<=m;i++){
        for(j=0;j<=m-i;j++){
            factor = pow(2,(i+1)); 
            trp[i][j]=(factor*trp[i-1][j+1]-trp[i-1][j])/(factor-1);
        }
    }

    return trp[m][0];
}

int main(){
    double a=0,b=M_PI/2;
    int n =3;
    for(int m=0;m<=4;m++){
        cout<<m<<": "<<rombTrap(a,b,m,n)<<endl;
    }
    return 0;
}