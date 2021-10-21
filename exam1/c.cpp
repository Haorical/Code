#include<bits/stdc++.h>
using namespace std;
vector<string> a;
int toNum(string s){
    int len=s.length();
    int ret=0;
    for(int i=0;i<len;i++){
        int t=s[i]-'0';
        ret=ret*10+t;
    }
    return ret;
}
int main(){
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            string tmp=a[i]+a[j];
            int t=toNum(tmp);
            if(t%k==0){
                cnt++;
            }
        }
    }
    cout<<cnt;
    system("pause");
    return 0;
}