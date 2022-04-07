#include<bits/stdc++.h>
using namespace std;
int aa[10000+10],bb[10000+10];
struct Node
{
    int data;
    bool good;
}node[20020];
bool cmp(Node x,Node y){
    return x.data>y.data;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(aa,0,sizeof aa);
        memset(bb,0,sizeof bb);
        int a,b,n;
        cin>>a>>b>>n;
        for(int i=0;i<a;i++){
            cin>>aa[i];
            node[i].data=aa[i];
            node[i].good=1;
        }
        for(int i=0;i<b;i++){
            cin>>bb[i];
            node[i+a].data=bb[i];
            node[i+a].good=0;
        }
        sort(node,node+a+b,cmp);
        int c=n/2;
        if(a<n-c){
            cout<<"-1"<<endl;
            continue;
        }
        
        int sum=0,p1=0,p2=0,cnt=0;
        for(int i=0;i<a+b;i++){
            if(cnt<n){
                if(!node[i].good&&p1<c){
                    p1++;
                    sum+=node[i].data;
                    cnt++;
                }else if(node[i].good){
                    sum+=node[i].data;
                    cnt++;
                }else{
                    continue;
                }
            }
        }
        cout<<sum<<endl;
    }
    system("pause");
}