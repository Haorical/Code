#include<bits/stdc++.h>
using namespace std;
const int N=12;
const double eps=1e-6;
int cf[N];
int main(){
    int t;
    while (~scanf("%d",&t))
    {
        if(t==0) break;
        for(int i=0;i<=t;i++){
            cin>>cf[i];
        }
        double l=-1e6,r=1e6,x,npv=0;
        while(1){
            npv=cf[0];
            x=(l+r)/2;
            for(int i=1;i<=t;i++){
                npv+=cf[i]/pow(x,i);
            }
            if(fabs(npv)<=eps) break;
            if(npv<0){
                r=x;
            }else{
                l=x;
            }
        }
        printf("%.2f\n",x-1);
    }
    
    system("pause");
    return 0;
}