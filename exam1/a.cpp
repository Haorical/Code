#include<bits/stdc++.h>
using namespace std;
char s[1000];
int main(){
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i+1]>='1'&&s[i+1]<='9'){
            int cnt=s[i+1]-'0';
            for(int j=0;j<cnt;j++){
                cout<<s[i];
            }
        }else{
            if(s[i]<'1'||s[i]>'9')
            cout<<s[i];
        }
    }
    system("pause");
    return 0;
}