#include<bits/stdc++.h>
using namespace std;
#define MAXN 200002
int n;
int a[MAXN],b[MAXN];
int cnta[MAXN];
int cntb[MAXN];
int main(){
    memset(cnta,0,sizeof(cnta));
    memset(cntb,0,sizeof(cntb));
    cin>>n;
    for(int i=0;i<2*n;i++){
        if(i<n) cin>>a[i];
        else cin>>b[i-n];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<b[i]<<endl;
    }
    for(int i=0;i<n;i++){
        int t=a[i];
        cnta[i]=1;
        t++;
        for(int j=i+1;j<n;j++){
            if(a[j]==t){
                cout<<t<<" ";
                cnta[i]++;
                cout<<a[i]<<endl;
                t++;
            }
        }
        t=b[i];
        cntb[i]=1;
        t++;
        for(int j=i+1;j<n;j++){
            if(b[j]==t){
                cntb[i]++;
                t+=1;
            }
        }        
    }
    int max=-0x3f3f3f3f;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]&&cnta[i]==cntb[j]){
                max=cnta[i];
            }
        }
    }
    if(max>0) cout<<max<<endl;
    else cout<<0<<endl;
    system("pause");
    return 0;
}