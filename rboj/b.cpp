#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[50][100010];
signed main(){
    fill(a[0],a[0]+50*100010,0);
    int n,q,op;
    cin>>n>>q;
    while(q--){
        ll c,l,r,k,t,j=1;
        cin>>op;
        if(op==1){
            cin>>c>>l>>r>>k;
            while(c){
                t=c%2;
                if(t){
                    for(int i=l;i<=r;i++){
                        a[j][i]+=k;
                    }
                }
                c/=2;
                j++;
            }
        }
        if(op==2){
            ll sum=0;
            cin>>c>>l>>r;
            while(c){
                t=c%2;
                if(t){
                    for(int i=l;i<=r;i++){
                        sum+=a[j][i];
                    }
                }
                c/=2;
                j++;
            }
            cout<<sum;
            if(q>=1){
                cout<<endl;
            }
        }
    }
    system("pause");
    //return 0;
}