//简单模拟
#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
set<string> s;
vector<string> v,v1;
map<string,int> m;
int main(){
    int n;
    string t1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t1;
        s.insert(t1);
    }
    int k;
    cin>>k;
    int zz=k;
    int t2,sum=0;
    while(k--){
        cin>>t1>>t2;
        v.push_back(t1);
        m[t1]=t2;
        sum+=t2;
    }
    for(int i=0;i<zz;i++){
        int s1=s.size();
        s.insert(v[i]);
        int s2=s.size();
        if(s2>s1&&zz*m[v[i]]>sum){
            v1.push_back(v[i]);
        }
    }
    if(v1.size()==0) cout<<"Bing Mei You";
    else{
        sort(v1.begin(),v1.end());
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<endl;
        }
    }
    system("pause");
    return 0;
}