#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    string s;
    cin>>k;
    int cnt=0;
    while(1){
        cin>>s;
        if(s=="End") break;
        if(cnt==k) {cout<<s<<endl;cnt=0;continue;}
        char t = s[0];
        if(t=='C') cout<<"Bu\n";
        else if(t=='J') cout<<"ChuiZi\n";
        else if(t=='B') cout<<"JianDao\n";
        cnt++;
    }
    system("pause");
    return 0;
}