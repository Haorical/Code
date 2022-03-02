#include <bits/stdc++.h>
using namespace std;
stack<char> s;
int main(){
    int a,b;
    cin>>a>>b;
    int c=a+b;
    if(c==0){
        cout<<0;
        return 0;
    }
    else if(c<0){
        int cnt=0;
        c=-c;
        int l=log10(c)+1;
        for(int i=1;i<=l;i++){
            s.push(c%10+'0');
            c/=10;
            cnt+=1;
            if(cnt==3&&i<l){
                s.push(',');
                cnt=0;
            }
        }
        s.push('-');
    }else{
        int cnt=0;
        int l=log10(c)+1;
        for(int i=1;i<=l;i++){
            s.push(c%10+'0');
            c/=10;
            cnt+=1;
            if(cnt==3&&i<l){
                s.push(',');
                cnt=0;
            }
        }
    }
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    system("pause");
}