#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        int ln = strlen(s);
        for(int i=0;i<ln;i++){
            if(s[i]=='?'){
                if(i==0){
                    if(s[1]=='a') s[0]='b';
                    else{
                        s[0]='a';
                    } 
                    continue;
                }
                if(i==ln-1){
                    if(s[ln-2]=='a') s[ln-1]='b';
                    else{
                        s[ln-1]='a';
                    } 
                    continue;
                }
                if(s[i-1]=='a'){
                    if(s[i+1]=='b'){
                        s[i]='c';
                    }else{
                        s[i]='b';
                    }
                }else if(s[i-1]=='b'){
                    if(s[i+1]=='a'){
                        s[i]='c';
                    }else{
                        s[i]='a';
                    }
                }else{
                    s[i]='a';
                }
            }
        }
        cout<<s<<endl;
    }
    system("pause");
    return 0;
}