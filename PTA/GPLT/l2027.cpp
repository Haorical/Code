// 初看前k大，线性时间选择 
// 手写快排一般过不了，用sort 
// 只是个简单的结构体排序
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,g,k;
struct node{
    string name;
    int sc;
    int mc;
}nd[N];
int cmp(node x,node y){
    if(x.sc==y.sc) return x.name<y.name;
    else return x.sc>y.sc;
}
int main(){
    cin>>n>>g>>k;
    string str;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>nd[i].name>>nd[i].sc;
        if(nd[i].sc>=g) sum+=50;
        else if(nd[i].sc>=60) sum+=20;
    }
    sort(nd,nd+n,cmp);
    cout<<sum<<endl;
    nd[0].mc=1;
    cout<<nd[0].mc<<' '<<nd[0].name<<' '<<nd[0].sc<<endl;
    int cnt=2;
    for(int i=1;i<n;i++){
        if(nd[i].sc==nd[i-1].sc) nd[i].mc=nd[i-1].mc;
        else nd[i].mc=cnt;
        // cout<<nd[i].mc<<' '<<nd[i].name<<' '<<nd[i].sc;        
        // if(nd[i].mc==k&&nd[i+1].sc<nd[i].sc) break;
        if(nd[i].mc>k) break; 
        //这样判断就比较简单，上面有逻辑问题会挂一个测试点
        cout<<nd[i].mc<<' '<<nd[i].name<<' '<<nd[i].sc;     
        if(i<n-1) cout<<endl;
        cnt++;
    }
    system("pause");
    return 0;
}