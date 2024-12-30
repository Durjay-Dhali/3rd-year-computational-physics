#include<iostream>
using namespace std;
int main(){
    int i, j, k, n;
    double A[20][20], x[20], c;
    cout<<"enter the order of matrix:"<<endl;
    cin>>n;
    cout<<"Enter the elements of augmented matrix row-wise:"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            cin>>A[i][j];
        }
    }
    //for elemintaon
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            if(i>j){
                c=A[i][j]/A[j][j];
                for(k=1;k<=n+1;k++){
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    //for matrix output:
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    //x[n] = A[n][n+1]/A[n][n];
    for(i=n;i>=1;i--){
        double sum=0;
        for(j=i+1;j<=n;j++){
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    cout<<"the solution is:"<<endl;
    for(i=1;i<=n;i++){
        cout<<"x"<<i<<"= "<<x[i]<<endl;
    }
    return 0;
}