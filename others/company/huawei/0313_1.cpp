// 判断两个IP地址是否属于同一网段
#include<cstdio>
#include<cstdlib>
int s1[5],s2[5],s3[5],res[5];
int main(){
    while(scanf("%d.%d.%d.%d",&s1[0],&s1[1],&s1[2],&s1[3])!=EOF){
        scanf("%d.%d.%d.%d",&s2[0],&s2[1],&s2[2],&s2[3]);
        scanf("%d.%d.%d.%d",&s3[0],&s3[1],&s3[2],&s3[3]);
        for(int i=0;i<4;i++){
            res[i]=s1[i]&s3[i];
        }
        int flag=1;
        for(int i=0;i<4;i++){
            if(res[i]==s2[i]&s3[i])
                continue;
            else{
                flag=0;
                break;
            }
        }
        printf("%d %d.%d.%d.%d",flag,res[0],res[1],res[2],res[3]);
    }
    return 0;
}