#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int cnt1=0,cnt2=0;
        int tn=n;
        while(tn){
            int a=tn%x;
            if(a==1) cnt1++;
            tn/=x;
        }
        tn=n;
        while(tn){
            int a=tn%y;
            if(a==1) cnt2++;
            tn/=y;
        }
        if(cnt1==cnt2){
            cout<<'='<<endl;
        }else if(cnt1>cnt2){
            cout<<'>'<<endl;
        }else{
            cout<<'<'<<endl;
        }
    }
    system("pause");
    return 0;
}