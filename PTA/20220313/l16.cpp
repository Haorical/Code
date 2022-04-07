#include<bits/stdc++.h>
using namespace std;
void judge(string s){
    int cnts=0,cntn=0,cntd=0;
    if(s.length()<6){
        cout<<"Your password is tai duan le.";
        return;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            cntd++;
        }else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            cnts++;
        }else if(s[i]>='0'&&s[i]<='9'){
            cntn++;
        }else{
            cout<<"Your password is tai luan le.";
            return;
        }
    }
    if(cntn==0){
        cout<<"Your password needs shu zi.";
        return;
    }else if(cnts==0){
        cout<<"Your password needs zi mu.";
        return;
    }
    cout<<"Your password is wan mei.";
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        judge(t);
        if(i<n-1) cout<<"\n";
    }
    system("pause");
    return 0;
}