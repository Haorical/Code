//考察堆这个数据结构，之前没学过
// 毫不意外的用STL写有两个测试点没过
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v(a,a+n);
    make_heap(v.begin(),v.end(),greater<int>());
    for(int i=0;i<m;i++){
        string s;
        int x,y;
        cin>>x>>s;
        if(s[0]=='a'){
            cin>>y>>s>>s;
            int t1=find(v.begin(),v.end(),x)-v.begin();
            if(v[t1+1]==y||v[t1-1]==y) cout<<'T';
            else cout<<'F';
        }else{
            cin>>s;
            if(s[0]=='a') {
                cin>>s>>s>>y;
                int t1=find(v.begin(),v.end(),y)-v.begin();
                if(v[2*t1+1]==x||v[2*t1+2]==x) cout<<'T';
                else cout<<'F';
            }else{
                cin>>s;
                if(s[0]=='r'){
                    if(x==v[0]) cout<<'T';
                    else cout<<'F';
                }else{
                    cin>>s>>y;
                    int t1=find(v.begin(),v.end(),x)-v.begin();
                    if(v[2*t1+1]==y||v[2*t1+2]==y) cout<<'T';
                    else cout<<'F';
                }
            }
        }
        if(i<m-1) cout<<endl;
    }
    system("pause");
    return 0;
}