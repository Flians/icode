// 矩阵旋转90度 ，M次

#include<iostream>
using namespace std;
int main(){
    int N,M;
    cin>>N;
    int a[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }
    cin>>M;
    int time=M%4;
    if(time==0){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j!=N-1)
                cout<<a[i][j]<<" ";
                else cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    else if(time==1){
        for(int i=0;i<N;i++){
            for(int j=N-1;j>=0;j--){
                if(j!=0)
                cout<<a[j][i]<<" ";
                else cout<<a[j][i];
            }
            cout<<endl;
        }
    }
    else if(time==2){
        for(int i=N-1;i>=0;i--){
            for(int j=N-1;j>=0;j--){
                if(j!=0)
                cout<<a[i][j]<<" ";
                else cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    else if(time==3){
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<N;j++){
                if(j!=N-1)
                cout<<a[j][i]<<" ";
                else cout<<a[j][i];
            }
            cout<<endl;
        }
    }
    return 0;
}