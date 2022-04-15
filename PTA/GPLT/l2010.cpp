//感觉是并查集，就是并查集
#include<bits/stdc++.h>
using namespace std;
const int N=110;
int f[N];
int flag[N][N];
int Find(int x){
    if(x==f[x]) return x;
    int a=Find(f[x]);
    return a;
}
void Union(int a,int b){
    a=Find(a); 
    b=Find(b);
    if(a!=b) f[a]=b; //容易错
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    int t1,t2,t3;
    for(int i=0;i<m;i++){
        cin>>t1>>t2>>t3;
        if(t3==1) Union(t1,t2);
        else flag[t1][t2]=flag[t2][t1]=1;
    }
    for(int i=0;i<k;i++){
        cin>>t1>>t2;
        //cout<<Find(t1)<<" "<<Find(t2)<<endl;
        if(Find(t1)==Find(t2)&&flag[t1][t2]!=1) cout<<"No problem";
        else if(Find(t1)!=Find(t2)&&flag[t1][t2]!=1) cout<<"OK";
        else if(Find(t1)==Find(t2)&&flag[t1][t2]==1) cout<<"OK but...";
        else cout<<"No way";
        if(i<k-1) cout<<endl;
    }
    system("pause");
    return 0;
}