#include<iostream>
using namespace std;
int main(){
    int A[3][3]={1,2,3,4,5,6,7,8,9};
    int B[3][3]={2,3,4,5,7,8,9,0};
    int C[3][3]={0};
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                C[i][k]+=A[i][j]*B[j][k];
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}