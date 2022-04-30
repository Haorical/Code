#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s;
    cin>>n;
    while(n--){
        s.clear();
        cin>>s>>m;
        m%=26; // 取余。。
        for(int i=0;i<s.length();i++){
            char t;
            if(s[i]>='A'&&s[i]<='Z')
            t=(s[i]-'A'+26-m)%26+'A';
            else if(s[i]>='a'&&s[i]<='z')
            t=(s[i]-'a'+26-m)%26+'a';
            else t=s[i];
            cout<<t;
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}