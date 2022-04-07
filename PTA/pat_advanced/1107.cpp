#include<bits/stdc++.h>
using namespace std;
const int N=1010; //最后发现数组开小了。。。。。
vector<int> father,Root;
int hb[N]; //不用数组试试
int n;;
void init(){
    for(int i=1;i<=n;i++){
        father[i]=i;
        Root[i]=0;
    }
}
int find(int x){
    if(x==father[x]){
        return x;
    }else{
        int a=find(father[x]);
        father[x]=a;
        return a;
    }
}
void Union(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if(fb!=fa) //没有father
        father[fb]=fa;
}
int main(){
    scanf("%d",&n);
    father.resize(n+1);
    Root.resize(n+1);
    memset(hb,0,sizeof(hb));
    init();
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d:",&k);
        for(int j=0;j<k;j++){
            int t;
            cin>>t;
            if(hb[t]==0){
                hb[t]=i;
            }
            Union(i,find(hb[t]));
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        Root[find(i)]++;
    }
    for(int j=1;j<=n;j++){
        if(Root[j]!=0){
            ans++;
        }
    }
    cout<<ans<<'\n';
    sort(Root.begin(),Root.end(),greater<int>());
    for(int j=0;j<ans;j++){
        cout<<Root[j];
        if(j!=ans-1) cout<<" ";
    }
    system("pause");
    return 0;
}