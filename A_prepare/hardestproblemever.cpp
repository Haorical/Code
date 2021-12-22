/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[27]={"VWXYZABCDEFGHIJKLMNOPQRSTU"},str[105];
    while(1){
        gets(str);
        if(strcmp(str,"START")==0) continue;
        if(strcmp(str,"END")==0) continue;
        if(strcmp(str,"ENDOFINPUT")==0) break;
        for(int i=0;i<strlen(str);i++){
            if(str[i]<'A'||str[i]>'Z') continue;
            str[i]=s[int(str[i]-'A')];
        }
        cout<<str;
    }
    system("pause");
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
char s[105],v[27]={"VWXYZABCDEFGHIJKLMNOPQRSTU"};
int main(){
    while(1){
        gets(s);
        if(strcmp(s,"START")==0) continue;
        else if(strcmp(s,"END")==0) continue;
        else if(strcmp(s,"ENDOFINPUT")==0) break;
        else{
            int l=strlen(s);
            for(int i=0;i<l;i++){
                if(s[i]>='A'&&s[i]<='Z')
                    s[i]=v[s[i]-'A'];
                else continue;
            }
        }
        puts(s);
    }
    system("pause");
    return 0;
}

//strlen

//27长数组

// &&