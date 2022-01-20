#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
    int a,b;
    cin>>a>>b;
    if(b==0){
        printf("%d/0=Error",a);
        continue;
    }
    int t1=a/b;
    if(a==b*t1){
        if(b>0)
            printf("%d/%d=%d",a,b,t1);
        else
            printf("%d/(%d)=%d",a,b,t1);
        continue;
    }
    double t=1.0*a/b;
    if(b>0){
        printf("%d/%d=%.2f",a,b,t);
        continue;
    }else{
        printf("%d/(%d)=%.2f",a,b,t);
        continue;
    }
    }
    system("pause");
    return 0;
}