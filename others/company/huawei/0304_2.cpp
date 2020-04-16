// k小朋友分n糖果

#include<iostream>
using namespace std;
int sss=0;
void huisu(int n,int k,int size[][1],int m,int sum){
    if(m>k)  return;
    if(sum>n)    return;
    if(sum==n){
        for(int i=0;i<k;i++){
            for(int j=0;j<size[i][0];j++)
                cout<<"*";
            if(i!=k-1)
                cout<<"|";
        }
        cout<<endl;
        return;
    }
    for(int j=n-sum;j>=0;j--){
            size[m][0]=j;
        //  cout<<"sum="<<sum<<" m="<<m<<" j="<<j<<endl; 
            huisu(n,k,size,m+1,sum+j);
        }
}
void huisu2(int n,int k,int size[][1],int m,int sum){
    if(m>k)  return;
    if(sum>n)    return;
    if(sum==n){
        sss++;
        return;
    }
    for(int j=n;j>=0;j--){
            size[m][0]=j;
            huisu2(n,k,size,m+1,sum+j);
        }
}
int main(){
    int n,k;
    cin>>n>>k;
    int t=0;
    //t=C(k-1) (n+1)
    int size[k][1];
    for(int i=0;i<k;i++)    size[i][0]=0;
    huisu2(n,k,size,0,0);
    cout<<sss<<endl;
    huisu(n,k,size,0,0);
    return 0;
}