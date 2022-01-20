#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,tmp;
int main(){
    int cnt=0;
    while(cin>>s){
        if(s==".") break;
        cnt++;
        if(cnt==2){
            s1=s;
        }
        if(cnt==14){
            s2=s;
        }
    }
    if(cnt<2){
        cout<<"Momo... No one is for you ...";
    }else if(cnt<14){
        tmp=s1+" is the only one for you...";
        cout<<tmp;
    }else{
        tmp=s1+" and "+s2+" are inviting you to dinner...";
        cout<<tmp;
    }
    system("pause");
    return 0;
}