// 动态规划最短编辑距离
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int change(string a,string b){
    int sum=0;
    int len1=a.length();
    int len2=b.length();
    int df[len1][len2];
    if(a[0]==b[0])  df[0][0]=0;
    else df[0][0]=1;
    for(int i=1;i<len2;i++){
        if(a[0]==b[i])
            df[0][i]=i;
        else    df[0][i]=df[0][i-1]+1;
    }
    for(int i=1;i<len1;i++){
        if(a[i]==b[0])
            df[i][0]=i;
        else    df[i][0]=df[i-1][0]+1;
    }
    for(int i=1;i<len1;i++){
        for(int j=1;j<len2;j++){
            if(a[i]==b[j]){
                df[i][j]=df[i-1][j-1];
            }
            else{
                df[i][j]=min(min(df[i-1][j],df[i][j-1])+1,df[i-1][j-1]+1);
            }
        }
    }
    return df[len1-1][len2-1];
}
int main(){
    int N;
    cin>>N;
    string str[N];
    string res[N];
    int sum=0;
    for(int i=0;i<N;i++){
        cin>>str[i];
    }
    for(int i=0;i<N;i++){
        cin>>res[i];
    }
    for(int i=0;i<N;i++){
        sum+=change(str[i],res[i]);
    }
    cout<<sum<<endl;
}