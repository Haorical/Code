#include<bits/stdc++.h>
using namespace std;
set<int> s;
vector<int> jj;
int a[100000];
int main(){
    int n;
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        if(j==1){
            int t;
            cin>>t;
            jj.push_back(j);
            break;
        }
        for(int k=0;k<j;k++){
            int t;
            cin>>t;
            s.insert(t);
        }
    }
    int m,t;
    cin>>m;
    int flag=0;
    for(int i=0;i<m;i++){
        cin>>t;
        for(auto j:jj){
            if(t==j){
                printf("%05d",t);
                a[t]=1;
                if(i<m-2){
                cout<<" ";
                break;
            }
            }
        }
        if(s.count(t)==0&&a[t]==0){
            printf("%05d",t);
            flag=1;
            a[t]=1;
            if(i<m-2){
                cout<<" ";
            }
        }
    }
    if(!flag) cout<<"No one is handsome";
    system("pause");
    return 0;
}