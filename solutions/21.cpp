#include<iostream>
using namespace std;
int main(){
    int n, i, j, k, p;
    double a[10][10], l[10][10]={0}, u[10][10]={0}, b[10], y[10]={0}, x[10]={0}, sum;
    //Taking Input:
    cout<<"Enter the order of matrix:"<<endl;
    cin>>n;
    cout<<"Enter all the coefficients of matrix row-wise:"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter the components of b matrix"<<endl;
    for(i=1;i<=n;i++){
        cin>>b[i];
    }
    //Factoring in L and U:
    for(k=1;k<=n;k++){
        u[k][k]=1;
        for(i=k;i<=n;i++){
            sum=0;
            for(p=1;p<=k-1;p++){
                sum+=l[i][p]*u[p][k];
            }
            l[i][k]=a[i][k]-sum;
        }
        for(j=k+1;j<=n;j++){
            sum=0;
            for(p=1;p<=k-1;p++){
                sum+=l[k][p]*u[p][j];
            }
            u[k][j]=(a[k][j]-sum)/l[k][k];
        }
    }
    //Displaying L and U matrix:
    cout<<"Lower triangular matrix:"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Upper triangular matrix:"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }
    //Finding and displaying y:
    for(i=1;i<=n;i++){
        sum=0;
        for(p=1;p<i;p++){
            sum+=l[i][p]*y[p];
        }
        y[i]=(b[i]-sum)/l[i][i];
    }
    cout<<"Y matrix:"<<endl;
    for(i=1;i<=n;i++){
        cout<<y[i]<<endl;
    }
    //Finding x:
    for(i=n;i>=1;i--){
        sum=0;
        for(p=n;p>i;p--){
            sum+=u[i][p]*x[p];
        }
        x[i]=y[i]-sum;
    }
    //Displaying solution:
    cout<<"Set of solution is:"<<endl;
    for(i=1;i<=n;i++){
        cout<<"x"<<i<<"= "<<x[i]<<endl;
    }
    return 0;
}