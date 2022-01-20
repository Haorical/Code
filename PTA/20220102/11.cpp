#include<bits/stdc++.h>
using namespace std;
string s[5002],s1[5002],s2[200];
int n;
map<string,int> mp;
bool check(string nm){
    for(int i=0;i<n;i++){
        if(nm==s[i]) return false;
    }
    return true;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int m,a;
    string b;
    cin>>m;
    int sum=0,arr;
    for(int i=0;i<m;i++){
        cin>>b>>a;
        s1[i]=b;
        mp[b]=a;
        sum+=a;
    }
    arr=sum/m;
    int k=0;
    for(int j=0;j<m;j++){
        if(check(s1[j])&&mp[s1[j]]>arr){
            s2[k++]=s1[j];
        }
    }
    if(k==0){
        cout<<"Bing Mei You";
        return 0;
    }
    sort(s2,s2+k);
    for(int z=0;z<k;z++){
        cout<<s2[z]<<endl;
    }
    system("pause");
    return 0;
}