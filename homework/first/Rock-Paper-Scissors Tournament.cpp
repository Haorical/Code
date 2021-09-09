#include<bits/stdc++.h>
using namespace std;
int win[102],loss[102];
int main(){
    
    int n;
    while(cin>>n){
        if(n==0) break;
        memset(win,0.0,sizeof(win));
        memset(loss,0.0,sizeof(loss));
        int k;
        cin>>k;
        int cnt=k*n*(n-1)/2;
        int p1,p2;
        string m1,m2;
        for(int i=0;i<cnt;i++){
            cin>>p1>>m1>>p2>>m2;
            if(m1!=m2){
                if((m1[0]=='r'&&m2[0]=='s')||(m1[0]=='s'&&m2[0]=='p')||(m1[0]=='p'&&m2[0]=='r')){
                    win[p1]++;
                    loss[p2]++;
                }else{
                    win[p2]++;
                    loss[p1]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            // cout<<win[i]<<endl;
            if(!win[i]&&!loss[i]) cout<<"-"<<endl;
            else{
                double a=double(win[i])/(double(win[i])+double(loss[i]));
                printf("%.3f\n",a);
            }
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}