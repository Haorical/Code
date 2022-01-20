#include<bits/stdc++.h>
using namespace std;
struct Node{
    string name;
    int num;
    double p;
}nd[10002];
bool cmp(Node a,Node b){
    return a.p<b.p;
}
int main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        string st;
        int nt;
        cin>>st>>nt;
        nd[i].name=st;
        nd[i].num=nt;
        sum+=nt;
    }
    int av=int(double(sum)/double(n*2)+0.5);
    for(int i=0;i<n;i++){
        nd[i].p=abs(nd[i].num-av);
    }
    sort(nd,nd+n,cmp);
    cout<<av<<" "<<nd[0].name;
    system("pause");
    return 0;
}