#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int l=s.length();
    int j,cnt;
    for (int i = 0; i < l; i++)
    {
        if (s[i]=='6')
        {
            j=i;
            cnt=1;
            for(int k=j+1;;k++){
                if(s[k]=='6'){
                    cnt++;
                }else break;
            }
            if(cnt>9){
                cout<<"27";
            }else if(cnt>3){
                cout<<'9';
            }else{
                for (int m = 0; m < cnt; m++)
                {
                    cout<<'6';
                }      
            }
            i+=cnt-1;
        }else{
            cout<<s[i];
        }
        
    }
    
    system("pause");
    return 0;
}