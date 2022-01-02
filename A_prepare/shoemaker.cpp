/*
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
struct job{
    double a;
    int num;
}p[maxn];
int n;
void init(){
    double a1,a2;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a1>>a2;
        p[i].a=a2/a1;
        p[i].num=i;
    }
}
bool cmp(job x,job y){
    if((x.a>y.a)||((x.a==y.a)&&(x.num<y.num))) return true;
    return false;
}
void work(){
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<n;i++) cout<<p[i].num<<" ";
    cout<<p[n].num<<endl;
}
int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        if(i>1) cout<<endl;
        init();
        work();
    }
    system("pause");
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;struct job{double a;int num;}p[maxn];int n;void init(){double a1,a2;cin>>n;for(int i=1;i<=n;i++){cin>>a1>>a2;p[i].a=a2/a1;p[i].num=i;}}bool cmp(job x,job y){if((x.a>y.a)||((x.a==y.a)&&(x.num<y.num)))return true;return false;}void work(){sort(p+1,p+n+1,cmp);for(int i=1;i<n;i++)cout<<p[i].num<<" ";cout<<p[n].num<<endl;}int main(){int T;cin>>T;for(int i=1;i<=T;i++){if(i>1)cout<<endl;init();work();}}