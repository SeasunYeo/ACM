#include<stdio.h>
#include<stdlib.h>
int ans[1001][11];
int ques[10]={1,1,1,1,1,1,1,1,1,1};
int t,n,m,k,num=0;
long f(int n){
    if(n==1)
        return 2;
    else
        return (n%2==0?1:m)*f(n/2)*f(n/2);    
}
int check(){
    int a[2048]={0};
    int nums=0,i,j,x,sum;
    for(i=0;i<n;i++){
            sum=0;
            x=1;
            for(j=0;j<m;j++){
                if(ques[j])
                    sum+=ans[i][j]*x;
                x*=2;
            }
            if(!a[sum]){
                a[sum]=1;
                ++nums;
            }
    }
    if(nums*(nums-1)/2>=k)
        ++num;
        return 1;
    return 0;
}
int search(int x){
    ques[x]=0;
    int j=check();
    if(j)
        for(int i=x;i<m;i++)
            if(ques[i])
                search(i);
    ques[x]=1;
    return 0;
}
int main(){
    int i,j,l,x;
    char ch;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        num=0;
        scanf("%d%d%d",&n,&m,&k);
        getchar();
        for(j=0;j<n;j++){
                for(l=0;l<m;l++){
                        scanf("%c",&ch);
                        if(ch=='A')
                            ans[j][l]=0;
                        if(ch=='B')
                            ans[j][l]=1;
                }            
                getchar();
        }
        if(((n*(n-1)/2)<k)||(f(m-1)<k)){
            num=0;
            printf("Case #%d: %d\n",i+1,num);
        }
        else{
            num=1;
            for(x=0;x<m;x++)
                if(ques[x])
                    search(x);
                printf("Case #%d: %d\n",i+1,num);
        }
    }
    return 0;    
}
