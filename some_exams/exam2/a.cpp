#include<bits/stdc++.h>
using namespace std;
string s[1000];
int w=0,w_r=0;
int h=0,h_r=0;
int a=0,b=0;
bool checkawa(string x){
    if(x.find("awa")!=string::npos) return true;
    return false;
}
bool checkqaq(string x){
    if(x.find("qaq")!=string::npos) return true;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        getline(cin,s[i]);
    }
    for(int i=1;i<=n;i++){
        string t=s[i];
        if(t[0]=='W'){
            if(checkawa(t)){
                w++;
            }
            if(checkqaq(t)){
                w_r++;
            }
        }else{
            if(checkqaq(t)){
                h++;
            }
            if(checkawa(t)){
                h_r++;
            }
        }
    }
    if(h_r>m){
        cout<<-1;
        return 0;
    }
    a=w+h;
    b=n-(w_r+h_r);
    cout<<a<<" "<<b<<endl;
    system("pause");
    return 0;
}