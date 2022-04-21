// 简单模拟
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> v[N];
int ad[N];
int main(){
    int n,m,k,t;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>t;
            v[i].push_back(t);
        }
    }
    int p,q;
    int now=1;
    for(int j=0;j<m;j++){
        cin>>p>>q;
        if(p==0){
            now=v[now][q-1];
        }
        if(p==1){
            ad[q]=now;
            cout<<now<<endl;
        }
        if(p==2){
            now=ad[q];
        }
        if(j==m-1) cout<<now;
    }
    system("pause");
    return 0;
}